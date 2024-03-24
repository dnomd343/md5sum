#pragma once

#include <array>

namespace md5 {

using BlockData = std::array<uint32_t, 16>;

// TODO: test the compile speed of T function
//static constexpr std::array<uint32_t, 64> kT = {
//    T(0x00), T(0x01), T(0x02), T(0x03), T(0x04), T(0x05), T(0x06), T(0x07),
//    T(0x08), T(0x09), T(0x0a), T(0x0b), T(0x0c), T(0x0d), T(0x0e), T(0x0f),
//    T(0x10), T(0x11), T(0x12), T(0x13), T(0x14), T(0x15), T(0x16), T(0x17),
//    T(0x18), T(0x19), T(0x1a), T(0x1b), T(0x1c), T(0x1d), T(0x1e), T(0x1f),
//    T(0x20), T(0x21), T(0x22), T(0x23), T(0x24), T(0x25), T(0x26), T(0x27),
//    T(0x28), T(0x29), T(0x2a), T(0x2b), T(0x2c), T(0x2d), T(0x2e), T(0x2f),
//    T(0x30), T(0x31), T(0x32), T(0x33), T(0x34), T(0x35), T(0x36), T(0x37),
//    T(0x38), T(0x39), T(0x3a), T(0x3b), T(0x3c), T(0x3d), T(0x3e), T(0x3f),
//};

static constexpr void BlockUpdate(md5_ctx *ctx, const BlockData &block) {
    auto A = ctx->A;
    auto B = ctx->B;
    auto C = ctx->C;
    auto D = ctx->D;

    auto A_ = A;
    auto B_ = B;
    auto C_ = C;
    auto D_ = D;

    MD5_UPDATE

    A += A_;
    B += B_;
    C += C_;
    D += D_;

    ctx->A = A;
    ctx->B = B;
    ctx->C = C;
    ctx->D = D;
}

static constexpr uint8_t GetByte(const char *data, const uint64_t index,
                                 const uint64_t len, const uint64_t padded_len) {
    if (index < len) {
        return data[index];
    }
    if (index == len) {
        return 0x80;
    }
    if (index >= padded_len - 8) {
        const uint64_t i = index - (padded_len - 8);
        return static_cast<uint8_t>(((len * 8) >> (i * 8)) & 0xff);
    }
    return 0;
}

static constexpr uint32_t GetWord(const char *data, const uint64_t index,
                                  const uint64_t len, const uint64_t padded_len) {
    auto b0 = static_cast<uint32_t>(GetByte(data, index + 0, len, padded_len));
    auto b1 = static_cast<uint32_t>(GetByte(data, index + 1, len, padded_len));
    auto b2 = static_cast<uint32_t>(GetByte(data, index + 2, len, padded_len));
    auto b3 = static_cast<uint32_t>(GetByte(data, index + 3, len, padded_len));
    return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
}

static constexpr BlockData GetBlock(const char *data, const uint64_t index,
                                    const uint64_t len, const uint64_t padded_len) {
    return BlockData {
        GetWord(data, index + 0, len, padded_len),
        GetWord(data, index + 4, len, padded_len),
        GetWord(data, index + 8, len, padded_len),
        GetWord(data, index + 12, len, padded_len),
        GetWord(data, index + 16, len, padded_len),
        GetWord(data, index + 20, len, padded_len),
        GetWord(data, index + 24, len, padded_len),
        GetWord(data, index + 28, len, padded_len),
        GetWord(data, index + 32, len, padded_len),
        GetWord(data, index + 36, len, padded_len),
        GetWord(data, index + 40, len, padded_len),
        GetWord(data, index + 44, len, padded_len),
        GetWord(data, index + 48, len, padded_len),
        GetWord(data, index + 52, len, padded_len),
        GetWord(data, index + 56, len, padded_len),
    };
}

inline constexpr CE MD5::HashCE(const char *data, uint64_t len) {
    md5_ctx ctx;
    const uint32_t padded_len = ((len + 64 + 8) / 64) * 64;
    for (uint32_t index = 0; index < padded_len; index += 64) {
        BlockUpdate(&ctx, GetBlock(data, index, len, padded_len));
    }
    return {ctx.A, ctx.B, ctx.C, ctx.D};
}

} // namespace md5
