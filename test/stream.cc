#include "md5.h"
#include "gtest/gtest.h"

using md5::MD5;

TEST(md5sum, stream) {
    std::string test_data(256 * 256, 0x00); // max -> 65536
    for (uint64_t i = 0; i < test_data.size(); ++i) {
        test_data[i] = static_cast<char>(i & 0xff);
    }

    MD5 md5;
    for (uint64_t size = 1; size <= 256; ++size) {
        auto expect = MD5::Hash(test_data.data(), size * 256);

        for (int times = 0; times < 256; ++times) {
            auto offset = test_data.data() + times * size;
            md5.Update(offset, size); // update multiple times
        }
        EXPECT_EQ(md5.Final().Digest(), expect);
        md5.Reset(); // reset for next round

        for (int times = 0; times < 256; ++times) {
            auto offset = test_data.data() + times * size;
            md5.Update(std::string_view {offset, size}); // update multiple times
        }
        EXPECT_EQ(md5.Final().Digest(), expect);
        md5.Reset(); // reset for next round
    }
}
