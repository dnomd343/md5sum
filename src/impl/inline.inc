#pragma once

namespace md5 {

inline MD5& MD5::Reset() {
    ctx_.A = MD5_A;
    ctx_.B = MD5_B;
    ctx_.C = MD5_C;
    ctx_.D = MD5_D;
    ctx_.size = 0;
    buffer_size_ = 0;
    return *this;
}

inline MD5& MD5::Final() {
    FinalImpl(buffer_, buffer_size_);
    return *this;
}

inline MD5& MD5::Update(const std::string_view &data) {
    return Update(data.data(), data.size());
}

inline std::string MD5::Hash(const std::string_view &data) {
    return Hash(data.data(), data.size());
}

inline std::string MD5::Hash(const void *data, uint64_t len) {
    MD5 md5;
    md5.FinalImpl(data, len);
    return md5.Digest();
}

inline constexpr CE MD5::HashCE(const std::string_view &data) {
    return HashCE(data.data(), data.size());
}

} // namespace md5
