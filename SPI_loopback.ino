// Sketch 3: SPI loopback (ESP32-S3)
// Wiring: jumper SPI_MOSI_PIN to SPI_MISO_PIN.

#include <SPI.h>

#define SPI_SCK_PIN  12
#define SPI_MOSI_PIN 11
#define SPI_MISO_PIN 13
#define SPI_CS_PIN   10

void setup() {
  Serial.begin(115200);
  pinMode(SPI_CS_PIN, OUTPUT);
  digitalWrite(SPI_CS_PIN, HIGH);
  SPI.begin(SPI_SCK_PIN, SPI_MISO_PIN, SPI_MOSI_PIN, SPI_CS_PIN);
  delay(1000);
}

void loop() {
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  digitalWrite(SPI_CS_PIN, LOW);
  uint8_t received = SPI.transfer(0xA5);
  digitalWrite(SPI_CS_PIN, HIGH);
  SPI.endTransaction();

  Serial.print("Sent 0xA5, received 0x");
  if (received < 16) Serial.print("0");
  Serial.println(received, HEX);

  delay(1000);
}
