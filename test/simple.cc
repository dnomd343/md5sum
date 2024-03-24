#include "md5.h"
#include "gtest/gtest.h"

using md5::MD5;

TEST(md5sum, empty) {
    auto expect = "d41d8cd98f00b204e9800998ecf8427e";

    MD5 md5;
    EXPECT_EQ(md5.Final().Digest(), expect);
    md5.Reset();
    EXPECT_EQ(md5.Final().Digest(), expect);
    md5.Reset();
    EXPECT_EQ(md5.Update("").Final().Digest(), expect);
}

TEST(md5sum, simple) {
    auto expect = "5227827849ea5e9d942ff40dbbfaffd6";

    EXPECT_EQ(MD5::Hash("dnomd343"), expect);

    auto result = std::string {MD5::HashCE("dnomd343").data(), 32};
    EXPECT_EQ(result, expect);

    MD5 md5;
    EXPECT_EQ(md5.Reset().Update("").Update("dnomd343").Final().Digest(), expect);
    EXPECT_EQ(md5.Reset().Update("dnomd").Update("343").Final().Digest(), expect);
    EXPECT_EQ(md5.Reset().Update("dnomd343").Final().Digest(), expect);
}
