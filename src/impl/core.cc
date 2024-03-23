#include <cstring>

#include "md5.h"
#include "sine.inc"
#include "algorithm.inc"

#define MD5_S(i)    value::S(i)
#define MD5_T(i)    value::T(i)
#define MD5_DATA(i) block[value::K(i)]

namespace md5 {

static constexpr unsigned char Padding[64] { 0x80, /* 0x00, ... */ };

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
        MD5_UPDATE
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
