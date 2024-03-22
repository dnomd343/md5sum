#include <cstring>

#include "md5.h"

namespace md5 {

// TODO: inline impl
MD5& MD5::Reset() {
    ctx_.A = MD5_A;
    ctx_.B = MD5_B;
    ctx_.C = MD5_C;
    ctx_.D = MD5_D;

    ctx_.size = 0;
    buffer_size_ = 0;
    return *this;
}

MD5& MD5::Update(const void *data, uint64_t len) {
    if (buffer_size_ != 0) {
        if (buffer_size_ + len < 64) { // buffer not filled
            std::memcpy(buffer_ + buffer_size_, data, len);
            buffer_size_ += len;
            return *this; // save into buffer and return
        }

        auto size = 64 - buffer_size_;
        std::memcpy(buffer_ + buffer_size_, data, size);
        md5_update(&ctx_, buffer_, 64); // fill and update with buffer
        data = reinterpret_cast<const char*>(data) + size;
        buffer_size_ = 0;
        len -= size;
    } // buffer is empty for now

    auto size = len & ~(uint64_t)0b111111;
    md5_update(&ctx_, data, size);
    data = reinterpret_cast<const char*>(data) + size;
    len &= 0b111111; // len -> [0, 64)

    if (len != 0) {
        std::memcpy(buffer_, data, len); // save remain data into buffer
        buffer_size_ = len;
    }
    return *this;
}

MD5& MD5::Update(const std::string_view &data) {
    return Update(data.data(), data.size());
}

MD5& MD5::Final() {
    md5_final(&ctx_, buffer_, buffer_size_);
    return *this;
}

std::string MD5::Digest() const {
    // TODO: perf convert speed
    char tmp[33];
    sprintf(tmp, "%08x%08x%08x%08x",
            __builtin_bswap32(ctx_.A),
            __builtin_bswap32(ctx_.B),
            __builtin_bswap32(ctx_.C),
            __builtin_bswap32(ctx_.D));
    return {tmp};
}

std::string MD5::Hash(const void *data, uint64_t len) {
    md5_ctx ctx;
    md5_final(&ctx, data, len);

    // TODO: perf convert speed
    char tmp[33];
    sprintf(tmp, "%08x%08x%08x%08x",
            __builtin_bswap32(ctx.A),
            __builtin_bswap32(ctx.B),
            __builtin_bswap32(ctx.C),
            __builtin_bswap32(ctx.D));
    return {tmp};
}

std::string MD5::Hash(const std::string_view &data) {
    return Hash(data.data(), data.size());
}

} // namespace md5
