## 1. Pin Table

| Signal | GPIO Used |
|--------|----------:|
| UART TX | 17 |
| UART RX | 18 |
| I²C SDA | 8 |
| I²C SCL | 9 |
| SPI SCK | 12 |
| SPI MOSI | 11 |
| SPI MISO | 13 |
| SPI CS | 10 |

- **UART Loopback** – Tests UART communication by transmitting and receiving data.
- **I²C Scanner** – Detects connected I²C devices and displays their addresses.
- **SPI Loopback** – Tests SPI communication by sending and receiving data.

## 2. Circuit Diagram
The diagram below shows how the ESP32-S3 is wired to the UART, I²C, and SPI interfaces tested in this lab.


<img width="2000" height="1414" alt="3" src="https://github.com/user-attachments/assets/257669a3-9876-4715-9ef8-71e2fd69a40a" />
Figure 1. UART Loopback Circuit Diagram

<img width="2000" height="1414" alt="5" src="https://github.com/user-attachments/assets/2039b782-b946-44ab-a04b-185c3e9a7595" />
Figure 2. I²C Scanner Circuit Diagram

<img width="2000" height="1414" alt="4" src="https://github.com/user-attachments/assets/1aeb37ea-4370-4345-9586-cca17f165408" />
Figure 3. SPI Loopback Circuit Diagram


## 3. Serial Monitor Outputs
- ## UART with wires
<img width="1261" height="875" alt="uart wth wires" src="https://github.com/user-attachments/assets/4375f21f-77a4-42d1-bdc4-fc236988dc1d" />
- UART Loopback Serial Monitor Output (PING received successfully)

  
- ## UART without wires
<img width="1262" height="1000" alt="uart wout wires" src="https://github.com/user-attachments/assets/43fedb55-6b96-4e1c-b93c-ec3651e71cb1" />


- ## I2C with wires
<img width="1272" height="947" alt="i2c with wire" src="https://github.com/user-attachments/assets/6dca1383-101e-4a5a-80fc-59498087cf1f" />
- I²C Scanner Serial Monitor Output showing a detected device at address 0x3C


- ## I2C without wires
<img width="1259" height="973" alt="i2c without wires" src="https://github.com/user-attachments/assets/b4845628-e6bb-442b-9bc2-3a1bd94bcd5a" />
- I²C Scanner Serial Monitor Output showing no I²C devices detected when the module is disconnected


- ## SPI with Jumper Wires
<img width="1263" height="998" alt="spi with wires" src="https://github.com/user-attachments/assets/70ad59d4-a22a-4acf-bd5e-df89a8a74f75" />
- SPI Loopback Serial Monitor Output showing successful data transmission and reception (0xA5)


- ## SPI with Jumper Wires
<img width="1259" height="991" alt="spi without wires" src="https://github.com/user-attachments/assets/3a3ba982-d07c-468f-8dfb-40d15f3c8e10" />
- SPI Loopback Serial Monitor Output showing received values of 0xFF and 0x00 without jumper wires


- ## Sketch at 9600, monitor at 115200 (UART Loopback)
<img width="1263" height="995" alt="115200baud sketch1" src="https://github.com/user-attachments/assets/4dc1e372-61e5-4280-b7cb-c6040be8d03a" />
- The UART Loopback Serial Monitor Output shows unreadable characters


- ## Sketch at 9600, monitor at 9600 (UART Loopback)
  <img width="1270" height="998" alt="9600baud" src="https://github.com/user-attachments/assets/862fd392-9fbb-4b43-96ec-7deaca67ccac" />
- The UART Loopback Serial Monitor Output shows repeated “PING” messages


## 4. Expected vs Observed

| Test | Expected | Observed |
|------|----------|----------|
| UART with jumper | PING received | PING received successfully |
| UART without jumper | No data received | No PING received |
| I2C with module | Device detected | Device detected at 0x3C |
| I2C without module | No device detected | No I2C device found |
| SPI with jumper | Data received correctly (0xA5) | 0xA5 received successfully |
| SPI without jumper | Incorrect data received | 0xFF and 0x00 received |
| Sketch at 9600, monitor at 115200 | Unreadable output | Unreadable characters appeared |
| Sketch at 9600, monitor at 9600 | Readable output | Repeated PING messages appeared |

## 5. Questions

**Why does UART need both sides to use the same baud rate, while SPI uses a clock line?**

   - UART needs both devices to have the same baud rate so they can read the data at the right speed. If their speeds are different, the data might be read incorrectly. SPI is different because it has a clock line that tells the receiver when to read the data.

**Why can two devices with the same address not share one I²C bus?**

   - If two devices have the same address, the controller might not know which device is responding. This can cause conflicts, so each device should have a unique address on the I²C bus.

**Why is CS set HIGH between SPI transfers?**

   - CS is set HIGH to stop the selected device from receiving data. This makes sure that the device won't respond to data meant for another device.


 
