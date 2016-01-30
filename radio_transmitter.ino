#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9, 10);

// Transmitter address
const uint64_t pipe = 0xE8E8F0F0E1LL;
const byte PayloadSize = 4;

unsigned long payload = 0;
unsigned long red = 9150000;
unsigned long yellow = 1151500;
unsigned long turquoise = 9001515;
unsigned long green = 9001500;
unsigned long blue = 9000015;
unsigned long pink = 9150015;

void setup(void) {
  radio.begin();

  // the following statements improve transmission range
  radio.setPayloadSize(PayloadSize); // setting the payload size to the needed value
  radio.setDataRate(RF24_250KBPS); // reducing bandwidth

  radio.openWritingPipe(pipe); // set the transmitter address
}

void loop(void) {
  //   for (byte step = 0; step < 5; step++) {
  //    payload = 111;
  //    radio.write(&payload, 1);
  //    delay(100);
  //  }


  radio.write(&red, sizeof(red));
  delay(5000);

  radio.write(&yellow, sizeof(yellow));
  delay(5000);

  payload = 110;
  radio.write(&payload, sizeof(payload));
  delay(5000);

  payload = 120;
  radio.write(&payload, sizeof(payload));
  delay(5000);

  radio.write(&turquoise, sizeof(turquoise));
  delay(5000);

  radio.write(&green, sizeof(green));
  delay(5000);

  payload = 130;
  radio.write(&payload, sizeof(payload));
  delay(5000);

  radio.write(&blue, sizeof(blue));
  delay(5000);

  radio.write(&pink, sizeof(pink));
  delay(5000);
}
