#pragma once

typedef struct {
    uint32_t lo, hi;
    uint32_t a, b, c, d;
    uint8_t buffer[64];
    uint32_t block[16];
} MD5_CTX;

void md5_init(MD5_CTX *ctx);
void md5_final(uint8_t *result, MD5_CTX *ctx);
void md5_update(MD5_CTX *ctx, const void *data, uint32_t size);
void md5_bin(const void *dat, size_t len, uint8_t out[16]);
