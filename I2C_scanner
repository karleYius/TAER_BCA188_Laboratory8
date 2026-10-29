// Sketch 2: I2C scanner (ESP32-S3)
// Wiring: I2C module on SDA_PIN, SCL_PIN, 3V3 and GND.

#include <Wire.h>

#define SDA_PIN 8
#define SCL_PIN 9

void setup() {
  Serial.begin(115200);
  delay(2000);  // give the Serial Monitor time to connect

  Wire.begin(SDA_PIN, SCL_PIN);

  int found = 0;
  for (uint8_t addr = 0x01; addr <= 0x7E; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found device at 0x");
      if (addr < 16) Serial.print("0");
      Serial.println(addr, HEX);
      found++;
    }
  }

  if (found == 0) {
    Serial.println("No I2C devices found");
  }
}

void loop() {
  // scan runs once at startup
}
