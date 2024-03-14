#include "md5_core.h"
#include "md5_math.h"

#define RA A, B, C, D
#define RB D, A, B, C
#define RC C, D, A, B
#define RD B, C, D, A

#define F(x, y, z) (z ^ (x & (y ^ z)))
#define G(x, y, z) (y ^ (z & (x ^ y)))
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | ~z))

#define CYCLIC(w, s) (w = (w << s) | (w >> (32 - s)))

#define STEP(i, f, a, b, c, d)               \
    do {                                     \
        a += f(b, c, d) + data[K(i)] + T(i); \
        CYCLIC(a, S(i));                     \
        a += b;                              \
    } while (0)

#define FF(i, ...) STEP((0x00 | i), F, __VA_ARGS__)
#define GG(i, ...) STEP((0x10 | i), G, __VA_ARGS__)
#define HH(i, ...) STEP((0x20 | i), H, __VA_ARGS__)
#define II(i, ...) STEP((0x30 | i), I, __VA_ARGS__)

#define MD5_ROUND(OP) \
    OP(0x0, RA); OP(0x1, RB); OP(0x2, RC); OP(0x3, RD); \
    OP(0x4, RA); OP(0x5, RB); OP(0x6, RC); OP(0x7, RD); \
    OP(0x8, RA); OP(0x9, RB); OP(0xa, RC); OP(0xb, RD); \
    OP(0xc, RA); OP(0xd, RB); OP(0xe, RC); OP(0xf, RD);

namespace md5 {

consteval int K(int index) {
    int i = index >> 4;
    const int step[] = {1, 5, 3, 7};
    const int begin[] = {0, 1, 5, 0};
    return (begin[i] + step[i] * index) & 0b1111;
}

consteval int S(int index) {
    const int map[][4] = {
        {7, 12, 17, 22},
        {5, 9, 14, 20},
        {4, 11, 16, 23},
        {6, 10, 15, 21},
    };
    return map[index >> 4][index & 0b11];
}

consteval uint32_t T(int index) {
    double val = math::sin(index + 1);
    return uint32_t(std::abs(val) * 0x100000000);
}

void md5_reset(struct md5_ctx *ctx) {
    ctx->A = MD5_A;
    ctx->B = MD5_B;
    ctx->C = MD5_C;
    ctx->D = MD5_D;
    ctx->size = 0;
}

void md5_process(struct md5_ctx *ctx, const void *buffer, uint64_t len) {
    const auto *data = (uint32_t *)buffer;
    const auto *limit = data + (len >> 2);

    uint32_t A = ctx->A;
    uint32_t B = ctx->B;
    uint32_t C = ctx->C;
    uint32_t D = ctx->D;

    while (data < limit) {
        uint32_t A_ = A;
        uint32_t B_ = B;
        uint32_t C_ = C;
        uint32_t D_ = D;

        MD5_ROUND(FF)
        MD5_ROUND(GG)
        MD5_ROUND(HH)
        MD5_ROUND(II)

        A += A_;
        B += B_;
        C += C_;
        D += D_;

        data += 16; // 512 bits
    }

    ctx->A = A;
    ctx->B = B;
    ctx->C = C;
    ctx->D = D;

    ctx->size += len; // processed size
}

} // namespace md5
