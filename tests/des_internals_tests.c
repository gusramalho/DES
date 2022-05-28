#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

#include "../src/des_internals.h"

char *intTobin(uint64_t value, char *buffer, int buf_size) {
    buffer += (buf_size - 1);

    for (int i = 63; i >= 0; i--) {
        *buffer-- = (value & 1) + '0';

        value >>= 1;
    }

    return buffer;
}

void test_permutedChoice1() {
  char buff[64];

  uint64_t key      = 0b0110011011010011001010010011101011100110010101011111000010010110;
  uint64_t expected = 0b0000000011010010011100110101110111101001101110110001000011001010;

  uint64_t result = permutedChoice1(key);

  printf("%ld\n", result);

  intTobin(result, buff, 64);

  printf(buff);

 assert(expected == result);
}

void test_leftOfPermutedChoice1() {
  uint64_t key      = 0b0000000011010010011100110101110111101001101110110001000011001010;
  uint32_t expected = 0b00001101001001110011010111011110;

  uint32_t result = leftOfPC1(key);
  printf("%" PRIu32 "\n%" PRIu32 "\n", expected, result);
 assert(expected == result);
}

void test_rightOfPermutedChoice1() {
  uint64_t key      = 0b0000000011010010011100110101110111101001101110110001000011001010;
  uint32_t expected = 0b00001001101110110001000011001010;

  uint32_t result = rightOfPC1(key);
  printf("%" PRIu32 "\n%" PRIu32 "\n", expected, result);
  assert(expected == result);
}

int main() {
  //test_permutedChoice1();
  test_leftOfPermutedChoice1();
  test_rightOfPermutedChoice1();


  return 0;
}
