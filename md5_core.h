#pragma once

#include <cstdint>

namespace md5 {

constexpr uint32_t MD5_A = 0x67452301;
constexpr uint32_t MD5_B = 0xefcdab89;
constexpr uint32_t MD5_C = 0x98badcfe;
constexpr uint32_t MD5_D = 0x10325476;

struct md5_ctx {
    uint32_t A = MD5_A;
    uint32_t B = MD5_B;
    uint32_t C = MD5_C;
    uint32_t D = MD5_D;
    uint64_t size = 0;
};

/// Reset md5 ctx with algorithm constants.
void md5_reset(md5_ctx *ctx);

/// Update md5 ctx with specified data, note that `len` is a multiple of 64.
void md5_update(md5_ctx *ctx, const void *buffer, uint64_t len);

/// Update and end the md5 hash with the specified data, the value of `len` has no limit.
void md5_final(md5_ctx *ctx, const void *buffer, uint64_t len);

} // namespace md5
