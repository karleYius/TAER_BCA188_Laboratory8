// Sketch 1: UART loopback (ESP32-S3)
// Wiring: jumper UART_TX_PIN to UART_RX_PIN.

#define UART_TX_PIN 17
#define UART_RX_PIN 18

unsigned long lastSend = 0;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, UART_RX_PIN, UART_TX_PIN);
  delay(1000);
  Serial.println("UART loopback started");
}

void loop() {
  // Send PING once per second
  if (millis() - lastSend >= 1000) {
    lastSend = millis();
    Serial2.println("PING");
  }

  // Print every byte received on the RX pin
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}
