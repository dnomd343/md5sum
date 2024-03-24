#pragma once

#include "sine.inc"

namespace md5::value {

/// Hexadecimal character mapping table.
constexpr char HexTable[] = {
    '0','1','2','3','4','5','6','7',
    '8','9','a','b','c','d','e','f',
};

/// MD5 fixed constants in little endian.
constexpr uint32_t kA = 0x67452301;
constexpr uint32_t kB = 0xefcdab89;
constexpr uint32_t kC = 0x98badcfe;
constexpr uint32_t kD = 0x10325476;

// In order to be compatible with C++17, the `consteval` keyword cannot be used
// here. The MD5 T-table constants will be macro-expanded and calculated.

constexpr uint32_t TCal(const int i) {
    const auto val = math::sin(i + 1);
    return static_cast<uint32_t>(math::abs(val) * 0x100000000);
}

#define MD5_TT \
    MD5_T(00) MD5_T(01) MD5_T(02) MD5_T(03) MD5_T(04) MD5_T(05) MD5_T(06) MD5_T(07) \
    MD5_T(08) MD5_T(09) MD5_T(0a) MD5_T(0b) MD5_T(0c) MD5_T(0d) MD5_T(0e) MD5_T(0f) \
    MD5_T(10) MD5_T(11) MD5_T(12) MD5_T(13) MD5_T(14) MD5_T(15) MD5_T(16) MD5_T(17) \
    MD5_T(18) MD5_T(19) MD5_T(1a) MD5_T(1b) MD5_T(1c) MD5_T(1d) MD5_T(1e) MD5_T(1f) \
    MD5_T(20) MD5_T(21) MD5_T(22) MD5_T(23) MD5_T(24) MD5_T(25) MD5_T(26) MD5_T(27) \
    MD5_T(28) MD5_T(29) MD5_T(2a) MD5_T(2b) MD5_T(2c) MD5_T(2d) MD5_T(2e) MD5_T(2f) \
    MD5_T(30) MD5_T(31) MD5_T(32) MD5_T(33) MD5_T(34) MD5_T(35) MD5_T(36) MD5_T(37) \
    MD5_T(38) MD5_T(39) MD5_T(3a) MD5_T(3b) MD5_T(3c) MD5_T(3d) MD5_T(3e) MD5_T(3f)

#define MD5_T(x) constexpr auto kT_##x = TCal(0x##x);
MD5_TT
#undef MD5_T

#define MD5_T(x) kT_##x,
/// MD5 T-table constant array.
constexpr std::array kT = {MD5_TT};
#undef MD5_T

#undef MD5_TT

} // namespace md5::value
