#include <inttypes.h>
#include <stdio.h>
#include "crc.h"

void test1(uint8_t const b) {
  printf("b=%02x crc=%02x\n", b, crc8_p93_next(0, b));
}

void test2(uint8_t const b1,uint8_t const b2) {
  printf("b1,2=%02x%02x crc=%02x\n", b1,b2, crc8_p93_2b(b1, b2));
}

int main() {
  test1(0x00);
  test1(0x55);
  test1(0xaa);
  test1(0xff);

  test2(0x00, 0x00);
  test2(0x80, 0x00);
  test2(0xb0, 0x30);
  test2(0xa0, 0x30);
  test2(0xe0, 0x69);
  test2(0xe0, 0x78);
  return 0;
}
