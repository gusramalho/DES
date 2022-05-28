#include "permutations.h"

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

uint64_t permutate56(uint64_t block, const int map[56]) {
  uint64_t res = 0;

  for (int i = 0; i < 56; i++) {
    int mappedIdx = map[i] - 1;

    uint64_t pos = (FIRST_BIT >> mappedIdx) & block;

    res |= mappedIdx >= i 
      ? pos << (mappedIdx - i) 
      : pos >> (i - mappedIdx);
  }

  return res >> 8;
}
