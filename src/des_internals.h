#ifndef DES_INTERNALS_H
#define DES_INTERNALS_H

#include <inttypes.h>
#include "permutations.h"

uint64_t initialPermutation(uint64_t block);

uint64_t finalPermutation(uint64_t block);

uint64_t permutedChoice1(uint64_t key);

uint32_t leftOfPC1(uint64_t key);

uint32_t rightOfPC1(uint64_t key);

uint32_t leftOf(uint64_t block);

uint32_t rightOf(uint64_t block);

uint64_t mergeBlockHalves(uint32_t left, uint32_t right);

uint64_t permutedChoice2(uint64_t key);

uint8_t subKeyRotationsOf(uint8_t index);

uint64_t expansionFn(uint32_t rightBlock);

uint8_t sbox(uint8_t block, uint8_t box);

uint64_t applySubstitionBoxes(uint64_t block);

uint32_t feistelFunction(uint32_t rightHalf, uint64_t subkey);

#endif
