#include <cstring>

#include "md5.h"

namespace md5 {

MD5& MD5::Update(const void *data, uint64_t len) {
    if (buffer_size_ != 0) {
        if (buffer_size_ + len < 64) { // buffer not filled
            std::memcpy(buffer_ + buffer_size_, data, len);
            buffer_size_ += len;
            return *this; // save into buffer and return
        }

        auto size = 64 - buffer_size_;
        std::memcpy(buffer_ + buffer_size_, data, size);
        UpdateImpl(buffer_, 64); // fill and update with buffer
        data = static_cast<const char*>(data) + size;
        buffer_size_ = 0;
        len -= size;
    } // buffer is empty for now

    data = UpdateImpl(data, len);
    len &= 0b111111; // len -> [0, 64)

    if (len != 0) {
        std::memcpy(buffer_, data, len); // save remain data into buffer
        buffer_size_ = len;
    }
    return *this;
}

static constexpr char HexTable[] = {
    '0','1','2','3','4','5','6','7',
    '8','9','a','b','c','d','e','f',
};

std::string MD5::Digest() const {
    std::string result {};
    result.resize(32);
    auto *src = reinterpret_cast<const uint8_t *>(&ctx_);
    for (int i = 0; i < 32; ++src) {
        result[i++] = HexTable[*src >> 4];
        result[i++] = HexTable[*src & 0b1111];
    }
    return result;
}

} // namespace md5
