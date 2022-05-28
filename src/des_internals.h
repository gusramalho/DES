#ifndef DES_INTERNALS_H
#define DES_INTERNALS_H

#include <inttypes.h>
#include "permutations.h"

uint64_t initialPermutation(uint64_t block);

uint32_t leftOf(uint64_t block);

uint32_t rightOf(uint64_t block);

#endif
