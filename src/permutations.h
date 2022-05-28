#ifndef PEMUTATIONS_H
#define PEMUTATIONS_H

#define FIRST_BIT_64 0x8000000000000000

#define FIRST_BIT_32 0x80000000

#include <inttypes.h>

uint64_t permutate64(uint64_t block, const int map[64]);

uint64_t permutate56(uint64_t block, const int map[56]);

uint64_t permutate56To48(uint64_t block, const int map[48]);

uint32_t rotateLeft(uint32_t value, uint8_t offset);

uint32_t rotateRight(uint32_t value, uint8_t offset);

uint32_t rotate28Left(uint32_t value, uint8_t offset);

uint64_t mergeSubkeys(uint64_t left, uint64_t right);

uint64_t permutate32To48(uint32_t, const int map[48]);

#endif
