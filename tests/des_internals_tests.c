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

void testLeftOfInitialPermutation() {
  uint64_t key      = 0b0110011011010011001010010011101011100110010101011111000010010110;
  uint32_t expected = 0b01100110110100110010100100111010;
  uint32_t result = leftOf(key);

  printf("%" PRIu32 "\n%" PRIu32 "\n", expected, result);

  assert(expected == result);
}

void testRightOfInitialPermutation() {
  uint64_t key      = 0b0110011011010011001010010011101011100110010101011111000010010110;
  uint32_t expected = 0b11100110010101011111000010010110;
  uint32_t result = rightOf(key);

  printf("%" PRIu32 "\n%" PRIu32 "\n", expected, result);
  
  assert(expected == result);
}

void testPermutedChoice1() {
  char buff[64];

  uint64_t key      = 0b0110011011010011001010010011101011100110010101011111000010010110;
  uint64_t expected = 0b0000000011010010011100110101110111101001101110110001000011001010;
  uint64_t result = permutedChoice1(key);

  printf("%ld\n", result);

  intTobin(result, buff, 64);

  printf("%s", buff);

  assert(expected == result);
}

void testLeftOfPermutedChoice1() {
  uint64_t key      = 0b0000000011010010011100110101110111101001101110110001000011001010;
  uint32_t expected = 0b00001101001001110011010111011110;
  uint32_t result = leftOfPC1(key);

  printf("%" PRIu32 "\n%" PRIu32 "\n", expected, result);

  assert(expected == result);
}

void testRightOfPermutedChoice1() {
  uint64_t key      = 0b0000000011010010011100110101110111101001101110110001000011001010;
  uint32_t expected = 0b00001001101110110001000011001010;

  uint32_t result = rightOfPC1(key);
  printf("%" PRIu32 "\n%" PRIu32 "\n", expected, result);
  assert(expected == result);
}

void testRotate28Left() {
  uint64_t key        = 0b00001001101110110001000011001010;
  uint32_t expected   = 0b00001011000100001100101010011011;

  uint32_t result = rotate28Left(key, 8);

  printf("exp: %" PRIu32 "\n res: %" PRIu32 "\n", expected, result);

  assert(expected == result);
}

void testMergeSubkeys() {
    uint64_t expected = 0b0000000011010010011100110101110111101001101110110001000011001010;
    uint32_t left     = 0b00001101001001110011010111011110;
    uint32_t right    = 0b00001001101110110001000011001010;

    uint64_t result = mergeSubkeys(left, right);

    printf("%ld\n%ld\n", expected, result);

    assert(expected == result);
}

void testPermutedChoice2() {
    uint64_t key56    = 0b0000000011010010011100100101110100001001101110110001000011001010;
    uint64_t expected = 0b0000000000000000001110001011001100010101000101010010111001001111;

    uint64_t result = permutedChoice2(key56);

    printf("%ld\n%ld\n", expected, result);

    assert(expected == result);
}

void testKeySchedule() {
  uint64_t originalKey = 0b0110011011010011001010010011101011100110010101011111000010010110;
  uint64_t pc1 = permutedChoice1(originalKey);

  uint32_t subKeyLeft = leftOf(pc1);
  uint32_t subKeyRight = rightOf(pc1);

  rotate28Left(subKeyLeft, 1);
}

int main() {
   testRotate28Left();
  // testPermutedChoice1();
  // testLeftOfInitialPermutation();
  // testRightOfInitialPermutation();
  // testLeftOfPermutedChoice1();
  // testRightOfPermutedChoice1();
  // testPermutedChoice2();
  // testMergeSubkeys();

  return 0;
}
