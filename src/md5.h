#pragma once

#include <string>
#include <cstdint>

static_assert(sizeof(uintptr_t) == 8,
    "Project only works on 64-bits architecture.");

static_assert(__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__,
    "Project only works on little-endian architecture.");

namespace md5 {

class MD5 {
public:
    MD5() = default;

    /// Reset for next round of hashing.
    MD5& Reset();

    /// Update md5 hash with specified data.
    MD5& Update(const std::string_view &data);

    /// Update md5 hash with specified data.
    MD5& Update(const void *data, uint64_t len);

    /// Stop streaming updates and calculate result.
    MD5& Final();

    /// Get the string result of md5.
    [[nodiscard]] std::string Digest() const;

public:
    /// Calculate the md5 hash value of the specified data.
    static std::string Hash(const std::string_view &data);

    /// Calculate the md5 hash value of the specified data.
    static std::string Hash(const void *data, uint64_t len);

private:
    static constexpr uint32_t MD5_A = 0x67452301;
    static constexpr uint32_t MD5_B = 0xefcdab89;
    static constexpr uint32_t MD5_C = 0x98badcfe;
    static constexpr uint32_t MD5_D = 0x10325476;

    struct md5_ctx {
        uint32_t A = MD5_A;
        uint32_t B = MD5_B;
        uint32_t C = MD5_C;
        uint32_t D = MD5_D;
        uint64_t size = 0; // processed size in byte
    };

private:
    md5_ctx ctx_;
    char buffer_[64] {};
    uint64_t buffer_size_ = 0; // size < 64

    /// Update md5 ctx with specified data, and return the pointer of unprocessed data (< 64 bytes).
    const void* UpdateImpl(const void *data, uint64_t len);

    /// Update and final the md5 hash with the specified data.
    void FinalImpl(const void *data, uint64_t len);
};

} // namespace md5

#include "impl/inline.inc"
