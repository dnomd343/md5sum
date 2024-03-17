#include "md5.h"

namespace md5 {

MD5& MD5::Reset() {
    ctx_.A = MD5_A;
    ctx_.B = MD5_B;
    ctx_.C = MD5_C;
    ctx_.D = MD5_D;

    ctx_.size = 0;
    buffer_size_ = 0;
    return *this;
}

MD5& MD5::Update(const void *buffer, uint64_t len) {
    // TODO: handle buffer_

    if (buffer_size_ == 0) {
        // TODO: len % 64 == 0
        md5_update(&ctx_, buffer, len);
    }

    // TODO: save extra data into buffer_

    return *this;
}

MD5& MD5::Final() {
    // TODO: call md5_final with buffer_
    return *this;
}

std::string MD5::Digest() {
    // TODO: return md5 digest in std::string (length = 16)
    return "";
}

std::string MD5::String() {
    // TODO: return md5 string (length = 32)
    return "";
}

std::string MD5::Hash(const std::string_view &data) {

    md5_ctx ctx;
    md5_final(&ctx, data.data(), data.size());

//    std::cout << std::hex << __builtin_bswap32(ctx.A);
//    std::cout << std::hex << __builtin_bswap32(ctx.B);
//    std::cout << std::hex << __builtin_bswap32(ctx.C);
//    std::cout << std::hex << __builtin_bswap32(ctx.D) << std::endl;

    // TODO: perf convert speed
    char tmp[33];
    sprintf(tmp, "%08x%08x%08x%08x",
            __builtin_bswap32(ctx.A),
            __builtin_bswap32(ctx.B),
            __builtin_bswap32(ctx.C),
            __builtin_bswap32(ctx.D));
    return {tmp};
}

} // namespace md5
