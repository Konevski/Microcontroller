### I2C Advantages source ( https://www.arrow.com/en/research-and-events/articles/spi-vs-i2c-protocols-pros-and-cons)
Users may prefer the I2C protocol for specific applications for two main reasons.

*1. Simplicity:*. The most apparent difference between I2C and SPI is that I2C works as a 2-wire bus, 
needing only serial data (SDA) and serial clock (SCK) lines for data transmission and synchronization. 
 SPI, on the other hand, requires four wires to control a single slave: SCK, master out slave in (MOSI), master in slave out (MISO), and slave select (SS).

*2. Easy add-ons:* When users need more than one slave device, SPI implements an additional SS pin for each one. 
 When an I2C system needs to implement new slave devices, they can simply “clip on” to the existing bus using a 7-bit addressing system to identify each module. 
This I2C scheme requires a proper address configuration but avoids the burden of extra wiring for each device.


### SPI Advantages

*1. Communication:*. Separate MISO/MOSI data lines mean that it’s capable of full-duplex communication, as opposed to I2C’s half-duplex operation, meaning that data send and receive transmissions must alternate.

*2. Speed:*. I2C originally defined data transfer rates at 100kbps, though we have seen it bump up to 400kbps or even up to 5Mbps in Ultra Fast-mode. SPI, however, does not define a top—or any—communications speed, and can be implemented at speeds of 10 Mbps or more.


### Advantages of Using UART

- Simple to operate, well documented as it is a widely used method with a lot of resources online

- No clock needed

- Parity bit to allow for error checking

### Disadvantages of Using UART

-Size of the data frame is limited to only 9 bits

-Cannot use multiple master systems and slaves

-Baud rates of each UART must be within 10% of each other to prevent data loss.

-Low data transmission speeds
