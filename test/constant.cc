#include "md5.h"
#include "gtest/gtest.h"

constexpr auto KTable = std::to_array<int>({
    0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 ,
    8 , 9 , 10, 11, 12, 13, 14, 15,
    1 , 6 , 11, 0 , 5 , 10, 15, 4 ,
    9 , 14, 3 , 8 , 13, 2 , 7 , 12,
    5 , 8 , 11, 14, 1 , 4 , 7 , 10,
    13, 0 , 3 , 6 , 9 , 12, 15, 2 ,
    0 , 7 , 14, 5 , 12, 3 , 10, 1 ,
    8 , 15, 6 , 13, 4 , 11, 2 , 9 ,
});

constexpr auto STable = std::to_array<int>({
    7 , 12, 17, 22, 7 , 12, 17, 22,
    7 , 12, 17, 22, 7 , 12, 17, 22,
    5 , 9 , 14, 20, 5 , 9 , 14, 20,
    5 , 9 , 14, 20, 5 , 9 , 14, 20,
    4 , 11, 16, 23, 4 , 11, 16, 23,
    4 , 11, 16, 23, 4 , 11, 16, 23,
    6 , 10, 15, 21, 6 , 10, 15, 21,
    6 , 10, 15, 21, 6 , 10, 15, 21,
});

constexpr auto TTable = std::to_array<uint32_t>({
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
});

#define TEST_KVAL(val) EXPECT_EQ(md5::value::K(val), KTable[val])
#define TEST_SVAL(val) EXPECT_EQ(md5::value::S(val), STable[val])
#define TEST_TVAL(val) EXPECT_EQ(md5::value::T(val), TTable[val])

TEST(md5sum, constant) {
    EXPECT_EQ(md5::value::kA, 0x67452301);
    EXPECT_EQ(md5::value::kB, 0xefcdab89);
    EXPECT_EQ(md5::value::kC, 0x98badcfe);
    EXPECT_EQ(md5::value::kD, 0x10325476);

    TEST_KVAL(0x00); TEST_KVAL(0x01); TEST_KVAL(0x02); TEST_KVAL(0x03);
    TEST_KVAL(0x04); TEST_KVAL(0x05); TEST_KVAL(0x06); TEST_KVAL(0x07);
    TEST_KVAL(0x08); TEST_KVAL(0x09); TEST_KVAL(0x0a); TEST_KVAL(0x0b);
    TEST_KVAL(0x0c); TEST_KVAL(0x0d); TEST_KVAL(0x0e); TEST_KVAL(0x0f);
    TEST_KVAL(0x10); TEST_KVAL(0x11); TEST_KVAL(0x12); TEST_KVAL(0x13);
    TEST_KVAL(0x14); TEST_KVAL(0x15); TEST_KVAL(0x16); TEST_KVAL(0x17);
    TEST_KVAL(0x18); TEST_KVAL(0x19); TEST_KVAL(0x1a); TEST_KVAL(0x1b);
    TEST_KVAL(0x1c); TEST_KVAL(0x1d); TEST_KVAL(0x1e); TEST_KVAL(0x1f);
    TEST_KVAL(0x20); TEST_KVAL(0x21); TEST_KVAL(0x22); TEST_KVAL(0x23);
    TEST_KVAL(0x24); TEST_KVAL(0x25); TEST_KVAL(0x26); TEST_KVAL(0x27);
    TEST_KVAL(0x28); TEST_KVAL(0x29); TEST_KVAL(0x2a); TEST_KVAL(0x2b);
    TEST_KVAL(0x2c); TEST_KVAL(0x2d); TEST_KVAL(0x2e); TEST_KVAL(0x2f);
    TEST_KVAL(0x30); TEST_KVAL(0x31); TEST_KVAL(0x32); TEST_KVAL(0x33);
    TEST_KVAL(0x34); TEST_KVAL(0x35); TEST_KVAL(0x36); TEST_KVAL(0x37);
    TEST_KVAL(0x38); TEST_KVAL(0x39); TEST_KVAL(0x3a); TEST_KVAL(0x3b);
    TEST_KVAL(0x3c); TEST_KVAL(0x3d); TEST_KVAL(0x3e); TEST_KVAL(0x3f);

    TEST_SVAL(0x00); TEST_SVAL(0x01); TEST_SVAL(0x02); TEST_SVAL(0x03);
    TEST_SVAL(0x04); TEST_SVAL(0x05); TEST_SVAL(0x06); TEST_SVAL(0x07);
    TEST_SVAL(0x08); TEST_SVAL(0x09); TEST_SVAL(0x0a); TEST_SVAL(0x0b);
    TEST_SVAL(0x0c); TEST_SVAL(0x0d); TEST_SVAL(0x0e); TEST_SVAL(0x0f);
    TEST_SVAL(0x10); TEST_SVAL(0x11); TEST_SVAL(0x12); TEST_SVAL(0x13);
    TEST_SVAL(0x14); TEST_SVAL(0x15); TEST_SVAL(0x16); TEST_SVAL(0x17);
    TEST_SVAL(0x18); TEST_SVAL(0x19); TEST_SVAL(0x1a); TEST_SVAL(0x1b);
    TEST_SVAL(0x1c); TEST_SVAL(0x1d); TEST_SVAL(0x1e); TEST_SVAL(0x1f);
    TEST_SVAL(0x20); TEST_SVAL(0x21); TEST_SVAL(0x22); TEST_SVAL(0x23);
    TEST_SVAL(0x24); TEST_SVAL(0x25); TEST_SVAL(0x26); TEST_SVAL(0x27);
    TEST_SVAL(0x28); TEST_SVAL(0x29); TEST_SVAL(0x2a); TEST_SVAL(0x2b);
    TEST_SVAL(0x2c); TEST_SVAL(0x2d); TEST_SVAL(0x2e); TEST_SVAL(0x2f);
    TEST_SVAL(0x30); TEST_SVAL(0x31); TEST_SVAL(0x32); TEST_SVAL(0x33);
    TEST_SVAL(0x34); TEST_SVAL(0x35); TEST_SVAL(0x36); TEST_SVAL(0x37);
    TEST_SVAL(0x38); TEST_SVAL(0x39); TEST_SVAL(0x3a); TEST_SVAL(0x3b);
    TEST_SVAL(0x3c); TEST_SVAL(0x3d); TEST_SVAL(0x3e); TEST_SVAL(0x3f);

    TEST_TVAL(0x00); TEST_TVAL(0x01); TEST_TVAL(0x02); TEST_TVAL(0x03);
    TEST_TVAL(0x04); TEST_TVAL(0x05); TEST_TVAL(0x06); TEST_TVAL(0x07);
    TEST_TVAL(0x08); TEST_TVAL(0x09); TEST_TVAL(0x0a); TEST_TVAL(0x0b);
    TEST_TVAL(0x0c); TEST_TVAL(0x0d); TEST_TVAL(0x0e); TEST_TVAL(0x0f);
    TEST_TVAL(0x10); TEST_TVAL(0x11); TEST_TVAL(0x12); TEST_TVAL(0x13);
    TEST_TVAL(0x14); TEST_TVAL(0x15); TEST_TVAL(0x16); TEST_TVAL(0x17);
    TEST_TVAL(0x18); TEST_TVAL(0x19); TEST_TVAL(0x1a); TEST_TVAL(0x1b);
    TEST_TVAL(0x1c); TEST_TVAL(0x1d); TEST_TVAL(0x1e); TEST_TVAL(0x1f);
    TEST_TVAL(0x20); TEST_TVAL(0x21); TEST_TVAL(0x22); TEST_TVAL(0x23);
    TEST_TVAL(0x24); TEST_TVAL(0x25); TEST_TVAL(0x26); TEST_TVAL(0x27);
    TEST_TVAL(0x28); TEST_TVAL(0x29); TEST_TVAL(0x2a); TEST_TVAL(0x2b);
    TEST_TVAL(0x2c); TEST_TVAL(0x2d); TEST_TVAL(0x2e); TEST_TVAL(0x2f);
    TEST_TVAL(0x30); TEST_TVAL(0x31); TEST_TVAL(0x32); TEST_TVAL(0x33);
    TEST_TVAL(0x34); TEST_TVAL(0x35); TEST_TVAL(0x36); TEST_TVAL(0x37);
    TEST_TVAL(0x38); TEST_TVAL(0x39); TEST_TVAL(0x3a); TEST_TVAL(0x3b);
    TEST_TVAL(0x3c); TEST_TVAL(0x3d); TEST_TVAL(0x3e); TEST_TVAL(0x3f);
}