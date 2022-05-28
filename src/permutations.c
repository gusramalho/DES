#include "permutations.h"
#include <inttypes.h>

uint64_t permutate64(uint64_t block, const int map[64]) {
  uint64_t res = 0;

  for (int i = 0; i < 64; i++) {
    int mappedIdx = map[i] - 1;

    uint64_t pos = (FIRST_BIT_64 >> mappedIdx) & block;

    res |= mappedIdx >= i 
      ? pos << (mappedIdx - i) 
      : pos >> (i - mappedIdx);
  }

  return res;
}

uint64_t permutate56(uint64_t block, const int map[56]) {
  uint64_t res = 0;

  for (int i = 0; i < 56; i++) {
    int mappedIdx = map[i] - 1;

    uint64_t pos = (FIRST_BIT_64 >> mappedIdx) & block;

    res |= mappedIdx >= i 
      ? pos << (mappedIdx - i) 
      : pos >> (i - mappedIdx);
  }

  return res >> 8;
}

uint64_t permutate56To48(uint64_t block, const int map[48]) {
  uint64_t res = 0;

  uint64_t block56 = block << 8;

  for (int i = 0; i < 48; i++) {
    int mappedIdx = map[i] - 1;

    uint64_t pos = (FIRST_BIT_64 >> mappedIdx) & block56;

    res |= mappedIdx >= i 
      ? pos << (mappedIdx - i) 
      : pos >> (i - mappedIdx);
  }

  return res >> 16;
}

uint32_t rotateLeft(uint32_t value, uint8_t offset) {
  return (value << offset) | (value >> (32 - offset));
}

uint32_t rotateRight(uint32_t value, uint8_t offset) {
  return (value >> offset) | (value << (32 - offset));
}

uint32_t rotate28Left(uint32_t value, uint8_t offset) {
  uint32_t raw = value << 4;
  uint32_t mask = 0;

  for (int i = 0; i < offset; i++) {
    mask |= FIRST_BIT_32 >> i;
  }

  uint32_t rightSlice = (mask & raw) >> (32 - offset);

  return ((raw << offset) >> 4) | rightSlice;
}
