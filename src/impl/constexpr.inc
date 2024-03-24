#pragma once

#include <array>

namespace md5::impl {

struct md5_ctx_ce {
    uint32_t A = MD5_A;
    uint32_t B = MD5_B;
    uint32_t C = MD5_C;
    uint32_t D = MD5_D;

    const char *data;
    uint64_t data_len, padded_len;

    constexpr md5_ctx_ce(const char *data, uint64_t len)
        : data(data), data_len(len), padded_len((len + 64 + 8) & ~0b111111ULL) {}
};

using Block = std::array<uint32_t, 16>; // single md5 block with 64 bytes

/// Get the data and padding byte of the specified index.
constexpr uint8_t GetByte(md5_ctx_ce *ctx, const uint64_t index) {
    if (index < ctx->data_len) // message data
        return ctx->data[index];
    if (index == ctx->data_len) // padding flag
        return 0x80;
    if (index < ctx->padded_len - 8) // padding content
        return 0x00;
    const auto offset = (index + 8 - ctx->padded_len) * 8;
    return static_cast<uint8_t>(0xff & (ctx->data_len * 8) >> offset);
}

/// Get the MD5 block content at the specified index.
constexpr Block GetBlock(md5_ctx_ce *ctx, const uint64_t index) {
    Block block {};
    for (int i = 0; i < 16; ++i) {
        auto offset = index + i * 4;
        (block[i] <<= 8) |= GetByte(ctx, offset + 3);
        (block[i] <<= 8) |= GetByte(ctx, offset + 2);
        (block[i] <<= 8) |= GetByte(ctx, offset + 1);
        (block[i] <<= 8) |= GetByte(ctx, offset + 0);
    }
    return block;
}

/// Convert origin MD5 integers to hexadecimal character array.
constexpr std::array<char, 32> DigestCE(std::array<uint32_t, 4> ctx) {
    std::array<char, 32> result {};
    for (uint32_t i = 0, val = 0; i < 32; val >>= 8) {
        if (!(i & 0b111))
            val = ctx[i >> 3];
        result[i++] = HexTable[(val >> 4) & 0b1111];
        result[i++] = HexTable[val & 0b1111];
    }
    return result;
}

constexpr std::array<char, 32> MD5::HashCE(const char *data, uint64_t len) {
    md5_ctx_ce ctx(data, len);
    for (uint32_t index = 0; index < ctx.padded_len; index += 64) {
        auto block = GetBlock(&ctx, index);
        auto A = ctx.A;
        auto B = ctx.B;
        auto C = ctx.C;
        auto D = ctx.D;
        MD5_UPDATE
        ctx.A += A;
        ctx.B += B;
        ctx.C += C;
        ctx.D += D;
    }
    return DigestCE({ctx.A, ctx.B, ctx.C, ctx.D});
}

} // namespace md5::impl
