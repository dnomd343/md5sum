#pragma once

namespace md5::impl {

struct md5_ce_ctx {
    uint32_t A = value::kA;
    uint32_t B = value::kB;
    uint32_t C = value::kC;
    uint32_t D = value::kD;
};

struct md5_ce {
    const char *data;
    uint64_t data_len, padded_len;

    constexpr md5_ce(const char *data, const uint64_t len)
        : data(data), data_len(len), padded_len((len + 64 + 8) & ~0b111111ULL) {}
};

using Block = std::array<uint32_t, 16>; // single md5 block with 64 bytes

/// Get the data and padding byte of the specified index.
constexpr uint8_t GetByte(const md5_ce *ctx, const uint64_t index) {
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
constexpr Block GetBlock(const md5_ce *ctx, const uint64_t index) {
    Block block {};
    for (int i = 0; i < 16; ++i) {
        const auto offset = index + i * 4;
        (block[i] <<= 8) |= GetByte(ctx, offset + 3);
        (block[i] <<= 8) |= GetByte(ctx, offset + 2);
        (block[i] <<= 8) |= GetByte(ctx, offset + 1);
        (block[i] <<= 8) |= GetByte(ctx, offset + 0);
    }
    return block;
}

/// Convert origin MD5 integers to hexadecimal character array.
constexpr std::array<char, 32> DigestCE(const std::array<uint32_t, 4> &ctx) {
    std::array<char, 32> result {};
    for (uint32_t i = 0, val = 0; i < 32; val >>= 8) {
        if (!(i & 0b111))
            val = ctx[i >> 3];
        result[i++] = value::HexTable[(val >> 4) & 0b1111];
        result[i++] = value::HexTable[val & 0b1111];
    }
    return result;
}

constexpr uint32_t Calc(const md5_ce_ctx &ctx, const int i) {
    if (i < 0x10)
        return ctx.D ^ (ctx.B & (ctx.C ^ ctx.D));
    if (i < 0x20)
        return ctx.C ^ (ctx.D & (ctx.B ^ ctx.C));
    if (i < 0x30)
        return ctx.B ^ ctx.C ^ ctx.D;
    return ctx.C ^ (ctx.B | ~ctx.D);
}

constexpr md5_ce_ctx Round(const Block &block, md5_ce_ctx ctx) {
    for (int i = 0; i < 64; ++i) {
        const auto a = ctx.A + Calc(ctx, i) + block[K(i)] + T(i);
        ctx.A = ctx.D;
        ctx.D = ctx.C;
        ctx.C = ctx.B;
        ctx.B += a << S(i) | a >> (32 - S(i));
    }
    return ctx;
}

constexpr std::array<char, 32> MD5::HashCE(const char *data, const uint64_t len) {
    md5_ce_ctx ctx;
    const md5_ce md5(data, len);
    for (uint32_t index = 0; index < md5.padded_len; index += 64) {
        const auto [A, B, C, D] = Round(GetBlock(&md5, index), ctx);
        ctx.A += A;
        ctx.B += B;
        ctx.C += C;
        ctx.D += D;
    }
    return DigestCE({ctx.A, ctx.B, ctx.C, ctx.D});
}

static_assert(MD5::HashCE("")[0] == 'd');

} // namespace md5::impl
