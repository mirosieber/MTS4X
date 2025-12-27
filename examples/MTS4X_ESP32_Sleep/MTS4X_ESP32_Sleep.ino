#include "MTS4x.h"
MTS4X Temp;


void setup() {
  Serial.begin(115200);
  delay(200);
  Temp.begin(SDA, SCL);
  delay(10);
  Temp.setConfig(MPS_8Hz, AVG_32, true);

  // Configure the wake up source and set to wake up every 10 seconds
  esp_sleep_enable_timer_wakeup(10 * 1000000); // 10 Sekunden (in Mikrosekunden)
}

uint32_t zeit = micros();
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
  esp_deep_sleep_start();
}