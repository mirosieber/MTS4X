#include "MTS4x.h"
#include "Pin.h"
MTS4X Temp;

#define TIME_TO_SLEEP  50


void setup() {
  Serial.begin(115200);
  delay(200);
  Temp.begin(I2C_LP_SDA,I2C_LP_SCL);
  delay(10);
  Temp.setConfig(MPS_8Hz, AVG_32, true);

  // Configure the wake up source and set to wake up every 10 seconds
  esp_sleep_enable_timer_wakeup(10 * 1000000); // 10 Sekunden (in Mikrosekunden)

  pinMode(RGB_ROT,OUTPUT);
  pinMode(RGB_GRUEN,OUTPUT);
  pinMode(RGB_BLAU,OUTPUT);
}

uint32_t zeit = micros();
uint8_t cnt=0;
void loop() {
  Serial.begin(115200);
  delay(2000);
  float temp=0;
  zeit = micros();
  Temp.startSingleMessurement();
  temp = Temp.readTemperature(true);
  Serial.println(micros()-zeit);
  Serial.print(temp);
  Serial.println(" °C");

  Serial.println("Going to sleep now");
  //esp_deep_sleep_start();
    digitalWrite(RGB_ROT, false);    // Rot an
    digitalWrite(RGB_GRUEN, false); // Andere Farben aus
    digitalWrite(RGB_BLAU, false);
  if (cnt == 0) {
    digitalWrite(RGB_ROT, true);    // Rot an
  } else if (cnt == 1) {
    digitalWrite(RGB_GRUEN, true);  // Grün an
  } else if (cnt == 2) {
    digitalWrite(RGB_BLAU, true);   // Blau an
  } else {
    cnt = -1; // Zurücksetzen, damit es bei 0 weitergeht
  }

  cnt++;
}