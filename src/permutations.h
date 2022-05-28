#ifndef PEMUTATIONS_H
#define PEMUTATIONS_H

#define FIRST_BIT 0x8000000000000000

#include <inttypes.h>

uint64_t permutate64(uint64_t block, const int map[64]);

uint64_t permutate56(uint64_t block, const int map[56]);

#endif
