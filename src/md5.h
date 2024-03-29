#pragma once

#include <array>
#include <string>
#include <cstdint>

static_assert(sizeof(uintptr_t) == 8,
    "Project only works on 64-bits architecture.");

static_assert(__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__,
    "Project only works on little-endian architecture.");

#include "impl/algorithm.inc"

namespace md5::impl {

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

    /// Calculate the md5 hash value of the specified data with constexpr.
    static constexpr std::array<char, 32> HashCE(const std::string_view &data);

    /// Calculate the md5 hash value of the specified data with constexpr.
    static constexpr std::array<char, 32> HashCE(const char *data, uint64_t len);

private:
    md5_ctx ctx_;
    char buffer_[64] {};
    uint64_t buffer_size_ = 0; // size < 64

    /// Update md5 ctx with specified data, and return the pointer of unprocessed data (< 64 bytes).
    const void* UpdateImpl(const void *data, uint64_t len);

    /// Update and final the md5 hash with the specified data.
    void FinalImpl(const void *data, uint64_t len);
};

} // namespace md5::impl

#include "impl/inline.inc"
#include "impl/constexpr.inc"

namespace md5 {

using MD5 = ::md5::impl::MD5;

} // namespace md5
