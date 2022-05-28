#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define FIRST_BIT 0x8000000000000000

const int IP[64] = {
  58, 50, 42, 34, 26, 18, 10, 2,
  60, 52, 44, 36, 28, 20, 12, 4,
  62, 54, 46, 38, 30, 22, 14, 6,
  64, 56, 48, 40, 32, 24, 16, 8,
  57, 49, 41, 33, 25, 17,  9, 1,
  59, 51, 43, 35, 27, 19, 11, 3,
  61, 53, 45, 37, 29, 21, 13, 5,
  63, 55, 47, 39, 31, 23, 15, 7
};

const int FP[64] = {
  40,	8, 48, 16, 56, 24, 64, 32,
  39,	7, 47, 15, 55, 23, 63, 31,
  38,	6, 46, 14, 54, 22, 62, 30,
  37,	5, 45, 13, 53, 21, 61, 29,
  36,	4, 44, 12, 52, 20, 60, 28,
  35,	3, 43, 11, 51, 19, 59, 27,
  34,	2, 42, 10, 50, 18, 58, 26,
  33,	1, 41, 9, 49, 17, 57, 25
};

uint64_t permutate64(uint64_t block, const int map[64]) {
  uint64_t res = 0;

  for (int i = 0; i < 64; i++) {
    int mappedIdx = map[i] - 1;

    uint64_t pos = (FIRST_BIT >> mappedIdx) & block;

    res |= mappedIdx >= i 
      ? pos << (mappedIdx - i) 
      : pos >> (i - mappedIdx);
  }

  return res;
}

uint64_t initialPermutation(uint64_t block) {
  return permutate64(block, IP);
}

uint32_t leftOf(uint64_t block) {
  return block >> 32;
}

uint32_t rightOf(uint64_t block) {
  return block << 32;
}

int main() {
  uint64_t e = 0b1000000000000000000000000000000000000000000000000000000000000000;
  uint64_t x = 0b0000000000000000000000000000000000000001000000000000000000000000;

  printf("%" PRIu32 "\n", rightOf(e) );

  return 0;
}
