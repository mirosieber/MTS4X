#include <MTS4X.h>

MTS4X tempSensor;

void setup() {
    Serial.begin(115200);
    tempSensor.begin(SDA, SCL, MEASURE_CONTINUOUS);
}

void loop() {
    float temperature = tempSensor.readTemperature();
    Serial.printf("Temperature: %.2f °C\n", temperature);
    delay(1000);
}