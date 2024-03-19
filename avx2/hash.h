

#include <stddef.h>
#include <stdint.h>

#define SHA3_256_RATE 136

int sha3_256(uint8_t *h, const uint8_t *in, size_t inlen);
