#include <cstring>

#include "md5.h"
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

#define STEP(i, f, a, b, c, d)                \
    do {                                      \
        a += f(b, c, d) + block[K(i)] + T(i); \
        CYCLIC(a, S(i));                      \
        a += b;                               \
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

static const unsigned char Padding[64] {0x80, /* 0x00, ... */};

consteval int K(int index) { // index -> [0, 64)
    const int step[] = {1, 5, 3, 7};
    const int begin[] = {0, 1, 5, 0};
    return (begin[index >> 4] + step[index >> 4] * index) & 0b1111;
}

consteval int S(int index) { // index -> [0, 64)
    const int map[][4] = {
        {7, 12, 17, 22},
        {5, 9, 14, 20},
        {4, 11, 16, 23},
        {6, 10, 15, 21},
    };
    return map[index >> 4][index & 0b11];
}

consteval uint32_t T(int index) { // index -> [0, 64)
    auto val = math::sin(index + 1);
    return static_cast<uint32_t>(std::abs(val) * 0x100000000);
}

const void* MD5::UpdateImpl(const void *data, uint64_t len) {
    auto *block = static_cast<const uint32_t *>(data);
    auto *limit = block + ((len &= ~0b111111ULL) >> 2);
    auto A = ctx_.A;
    auto B = ctx_.B;
    auto C = ctx_.C;
    auto D = ctx_.D;

    while (block < limit) {
        auto A_ = A;
        auto B_ = B;
        auto C_ = C;
        auto D_ = D;
        MD5_ROUND(FF)
        MD5_ROUND(GG)
        MD5_ROUND(HH)
        MD5_ROUND(II)
        A += A_;
        B += B_;
        C += C_;
        D += D_;
        block += 16; // move to next block
    }

    ctx_.A = A;
    ctx_.B = B;
    ctx_.C = C;
    ctx_.D = D;
    ctx_.size += len;
    return static_cast<const void *>(limit);
}

void MD5::FinalImpl(const void *data, uint64_t len) {
    if (len >= 120) { // len -> [64 + 56, INF)
        data = UpdateImpl(data, len);
        len &= 0b111111; // len -> [0, 64)
    }

    unsigned char buffer[128]; // 2 blocks
    std::memcpy(buffer, data, len);
    uint64_t total = (ctx_.size + len) << 3; // total number in bit

    if (len < 56) { // len -> [0, 56)
        std::memcpy(buffer + len, Padding, 56 - len);
        std::memcpy(buffer + 56, &total, 8);
        UpdateImpl(buffer, 64); // update 1 block
    } else { // len -> [56, 64 + 56)
        std::memcpy(buffer + len, Padding, 120 - len);
        std::memcpy(buffer + 120, &total, 8);
        UpdateImpl(buffer, 128); // update 2 blocks
    }
}

} // namespace md5
