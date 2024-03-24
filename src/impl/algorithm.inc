#pragma once

#define MD5_R1 A, B, C, D
#define MD5_R2 D, A, B, C
#define MD5_R3 C, D, A, B
#define MD5_R4 B, C, D, A

#define MD5_F(x, y, z) (z ^ (x & (y ^ z)))
#define MD5_G(x, y, z) (y ^ (z & (x ^ y)))
#define MD5_H(x, y, z) (x ^ y ^ z)
#define MD5_I(x, y, z) (y ^ (x | ~z))

#define MD5_CYC(w, s) (w = (w << s) | (w >> (32 - s)))

#define MD5_STEP(i, f, a, b, c, d)            \
    do {                                      \
        a += f(b, c, d) + block[K(i)] + T(i); \
        MD5_CYC(a, S(i));                     \
        a += b;                               \
    } while (0)

#define MD5_FF(i, ...) MD5_STEP((0x00 | i), MD5_F, __VA_ARGS__)
#define MD5_GG(i, ...) MD5_STEP((0x10 | i), MD5_G, __VA_ARGS__)
#define MD5_HH(i, ...) MD5_STEP((0x20 | i), MD5_H, __VA_ARGS__)
#define MD5_II(i, ...) MD5_STEP((0x30 | i), MD5_I, __VA_ARGS__)

#define MD5_ROUND(OP)                                                   \
    OP(0x0, MD5_R1); OP(0x1, MD5_R2); OP(0x2, MD5_R3); OP(0x3, MD5_R4); \
    OP(0x4, MD5_R1); OP(0x5, MD5_R2); OP(0x6, MD5_R3); OP(0x7, MD5_R4); \
    OP(0x8, MD5_R1); OP(0x9, MD5_R2); OP(0xa, MD5_R3); OP(0xb, MD5_R4); \
    OP(0xc, MD5_R1); OP(0xd, MD5_R2); OP(0xe, MD5_R3); OP(0xf, MD5_R4);

#define MD5_UPDATE \
    MD5_ROUND(MD5_FF) MD5_ROUND(MD5_GG) MD5_ROUND(MD5_HH) MD5_ROUND(MD5_II)

#include "value.inc"

namespace md5::impl {

struct md5_ctx {
    uint32_t A = value::kA;
    uint32_t B = value::kB;
    uint32_t C = value::kC;
    uint32_t D = value::kD;
    uint64_t size = 0; // processed size in byte
};

/// MD5 data block index, input between 0 and 63.
constexpr int K(const int i) {
    constexpr int step[4] = {1, 5, 3, 7};
    constexpr int begin[4] = {0, 1, 5, 0};
    return (begin[i >> 4] + step[i >> 4] * i) & 0b1111;
}

/// MD5 circular shift times, input between 0 and 63.
constexpr int S(const int i) {
    constexpr int shift[4][4] = {
        {7, 12, 17, 22},
        {5, 9, 14, 20},
        {4, 11, 16, 23},
        {6, 10, 15, 21},
    };
    return shift[i >> 4][i & 0b11];
}

/// MD5 T-table constant, input between 0 and 63.
constexpr uint32_t T(const int i) {
    return value::kT[i];
}

static_assert(K(0) != K(63), "invalid constexpr");
static_assert(S(0) != S(63), "invalid constexpr");
static_assert(T(0) != T(63), "invalid constexpr");

} // namespace md5::impl
