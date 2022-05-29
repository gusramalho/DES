#ifndef DES_H
#define DES_H

#include "des_internals.h"

uint64_t encrypt(uint64_t plainText, uint64_t key);

uint64_t decrypt(uint64_t data, uint64_t key);

#endif
