#include <gtest/gtest.h>

#include "md5.h"

using namespace md5;

TEST(md5sum, hash) {
    auto test_data = [](uint8_t size) -> std::string {
        std::string data {};
        data.reserve(size);
        for (uint8_t i = 0; i < size; ++i) {
            data.push_back(static_cast<char>(i));
        }
        return data;
    };

    EXPECT_EQ(MD5::Hash(test_data(0x00)), "d41d8cd98f00b204e9800998ecf8427e");
    EXPECT_EQ(MD5::Hash(test_data(0x01)), "93b885adfe0da089cdf634904fd59f71");
    EXPECT_EQ(MD5::Hash(test_data(0x02)), "441077cc9e57554dd476bdfb8b8b8102");
    EXPECT_EQ(MD5::Hash(test_data(0x03)), "b95f67f61ebb03619622d798f45fc2d3");
    EXPECT_EQ(MD5::Hash(test_data(0x04)), "37b59afd592725f9305e484a5d7f5168");
    EXPECT_EQ(MD5::Hash(test_data(0x05)), "d05374dc381d9b52806446a71c8e79b1");
    EXPECT_EQ(MD5::Hash(test_data(0x06)), "d15ae53931880fd7b724dd7888b4b4ed");
    EXPECT_EQ(MD5::Hash(test_data(0x07)), "9aa461e1eca4086f9230aa49c90b0c61");
    EXPECT_EQ(MD5::Hash(test_data(0x08)), "3677509751ccf61539174d2b9635a7bf");
    EXPECT_EQ(MD5::Hash(test_data(0x09)), "a6e7d3b46fdfaf0bde2a1f832a00d2de");
    EXPECT_EQ(MD5::Hash(test_data(0x0a)), "c56bd5480f6e5413cb62a0ad9666613a");
    EXPECT_EQ(MD5::Hash(test_data(0x0b)), "5b86fa8ad8f4357ea417214182177be8");
    EXPECT_EQ(MD5::Hash(test_data(0x0c)), "50a73d7013e9803e3b20888f8fcafb15");
    EXPECT_EQ(MD5::Hash(test_data(0x0d)), "b20d4797e23eea3ea5778970d2e226f3");
    EXPECT_EQ(MD5::Hash(test_data(0x0e)), "aa541e601b7b9ddd0504d19866350d4e");
    EXPECT_EQ(MD5::Hash(test_data(0x0f)), "58b7ce493ac99c66058538dacb1e3c94");

    EXPECT_EQ(MD5::Hash(test_data(0x10)), "1ac1ef01e96caf1be0d329331a4fc2a8");
    EXPECT_EQ(MD5::Hash(test_data(0x11)), "1bdd36b0a024c90db383512607293692");
    EXPECT_EQ(MD5::Hash(test_data(0x12)), "633ab81aea5942052b794524e1a28477");
    EXPECT_EQ(MD5::Hash(test_data(0x13)), "2d325313eb5df436c078435fa0f5eff1");
    EXPECT_EQ(MD5::Hash(test_data(0x14)), "1549d1aae20214e065ab4b76aaac89a8");
    EXPECT_EQ(MD5::Hash(test_data(0x15)), "7e437c81824d3982e70c88b5da8ea94b");
    EXPECT_EQ(MD5::Hash(test_data(0x16)), "2f5f7e7216832ae19c353023618a35a8");
    EXPECT_EQ(MD5::Hash(test_data(0x17)), "6535e52506c27eaa1033891ff4f3a74e");
    EXPECT_EQ(MD5::Hash(test_data(0x18)), "8bd9c8efbbac58748951ca5a45cfd386");
    EXPECT_EQ(MD5::Hash(test_data(0x19)), "d983c63bf41853056787fe1bb764dbff");
    EXPECT_EQ(MD5::Hash(test_data(0x1a)), "b4f24c1219fb00d081c4020c56263451");
    EXPECT_EQ(MD5::Hash(test_data(0x1b)), "b0ae6708c5e1be10668f57d3916cf423");
    EXPECT_EQ(MD5::Hash(test_data(0x1c)), "ba7bb5ad4dba5bde028703007969cb25");
    EXPECT_EQ(MD5::Hash(test_data(0x1d)), "ea880e16eac1b1488aff8a25d11d6271");
    EXPECT_EQ(MD5::Hash(test_data(0x1e)), "c7172f0903c4919eb232f18ab7a30c42");
    EXPECT_EQ(MD5::Hash(test_data(0x1f)), "e9e77893ba926e732f483282f416ffac");

    EXPECT_EQ(MD5::Hash(test_data(0x20)), "b4ffcb23737cec315a4a4d1aa2a620ce");
    EXPECT_EQ(MD5::Hash(test_data(0x21)), "5506a276a0a9acc3093f9169c73cf8c5");
    EXPECT_EQ(MD5::Hash(test_data(0x22)), "e5a849897d9cc0b25b286c1f0bfb50e3");
    EXPECT_EQ(MD5::Hash(test_data(0x23)), "f54fa30ea7b26d3e11c54d3c8451bcf0");
    EXPECT_EQ(MD5::Hash(test_data(0x24)), "07602fe0229e486957081a49e3f06f83");
    EXPECT_EQ(MD5::Hash(test_data(0x25)), "7c4bba98253ca834bf9ed43fd8b2f959");
    EXPECT_EQ(MD5::Hash(test_data(0x26)), "cf8df427548bbfdb1e11143fdf008b85");
    EXPECT_EQ(MD5::Hash(test_data(0x27)), "1431a6895a8f435755395f9ba83e76bf");
    EXPECT_EQ(MD5::Hash(test_data(0x28)), "30dd5e4cae35ba892cc66d7736723980");
    EXPECT_EQ(MD5::Hash(test_data(0x29)), "8ee247a1063931bedaf4c2fa3e4e261a");
    EXPECT_EQ(MD5::Hash(test_data(0x2a)), "c32ceee2d2245df8589f94fcda0c9f2c");
    EXPECT_EQ(MD5::Hash(test_data(0x2b)), "f25fa0e071d1f1cdc6632c6b673bccd5");
    EXPECT_EQ(MD5::Hash(test_data(0x2c)), "370491b643e97577f4f74bd88576d1ec");
    EXPECT_EQ(MD5::Hash(test_data(0x2d)), "b292bf16e3aafaf41f19c921068214f8");
    EXPECT_EQ(MD5::Hash(test_data(0x2e)), "52921aae5ccc9b6e8e45853419d0c80f");
    EXPECT_EQ(MD5::Hash(test_data(0x2f)), "f1375be31969155ef76f04741cd861d7");

    EXPECT_EQ(MD5::Hash(test_data(0x30)), "04605ca542b2d82b9886a4b4b9acfb1c");
    EXPECT_EQ(MD5::Hash(test_data(0x31)), "fa887ba0fa491faaacbb82bc5fefcd5b");
    EXPECT_EQ(MD5::Hash(test_data(0x32)), "06470e932ad7c7cedf548b5ccb9d4806");
    EXPECT_EQ(MD5::Hash(test_data(0x33)), "ad130b245e2dd894267cb0ddc532d169");
    EXPECT_EQ(MD5::Hash(test_data(0x34)), "a9eeb95053682248608e97d79e89ca82");
    EXPECT_EQ(MD5::Hash(test_data(0x35)), "cc26a3dc608268b98ecd1f3946c4b718");
    EXPECT_EQ(MD5::Hash(test_data(0x36)), "33dd62a2df6538daf1cf821d9cde61f9");
    EXPECT_EQ(MD5::Hash(test_data(0x37)), "6912ee65fff2d9f9ce2508cddf8bcda0");
    EXPECT_EQ(MD5::Hash(test_data(0x38)), "51fdd1acda72405dfdfa03fcb85896d7");
    EXPECT_EQ(MD5::Hash(test_data(0x39)), "5320ef4c17ef34a0cf2db763338d25eb");
    EXPECT_EQ(MD5::Hash(test_data(0x3a)), "9f4f41b5cde885f94cfc0e06e78f929d");
    EXPECT_EQ(MD5::Hash(test_data(0x3b)), "e39965bc00ecacd90fd875f77eff499a");
    EXPECT_EQ(MD5::Hash(test_data(0x3c)), "63ed72093ae09e2c8553ee069e63d702");
    EXPECT_EQ(MD5::Hash(test_data(0x3d)), "0d08fc14ac5baa37792377355dbad0ae");
    EXPECT_EQ(MD5::Hash(test_data(0x3e)), "f3cdffe2e160a061754a06dafcfd688b");
    EXPECT_EQ(MD5::Hash(test_data(0x3f)), "48a6295221902e8e0938f773a7185e72");

    EXPECT_EQ(MD5::Hash(test_data(0x40)), "b2d3f56bc197fd985d5965079b5e7148");
    EXPECT_EQ(MD5::Hash(test_data(0x41)), "8bd7053801c768420faf816fadba971c");
    EXPECT_EQ(MD5::Hash(test_data(0x42)), "e58b3261a467f02ba51b215c013df4c3");
    EXPECT_EQ(MD5::Hash(test_data(0x43)), "73062234b55754c3383480d5ef70dce5");
    EXPECT_EQ(MD5::Hash(test_data(0x44)), "f752ebd79a813ef27c35bed69e2ee69f");
    EXPECT_EQ(MD5::Hash(test_data(0x45)), "10907846eb89ef5dc5d4935a09dad0e7");
    EXPECT_EQ(MD5::Hash(test_data(0x46)), "5f1f5f64b84400fb9ad6d8ecd9c142a0");
    EXPECT_EQ(MD5::Hash(test_data(0x47)), "3157d7bb98a202b50cf0c437aa216c39");
    EXPECT_EQ(MD5::Hash(test_data(0x48)), "70e7ade70281b0afcb1d4ed13efc2e25");
    EXPECT_EQ(MD5::Hash(test_data(0x49)), "0bb96a503b1626c9ab16c1291c663e75");
    EXPECT_EQ(MD5::Hash(test_data(0x4a)), "5bed4126b3c973f685fcf92a738d4dab");
    EXPECT_EQ(MD5::Hash(test_data(0x4b)), "7523c240f2a44e86dd22504ca49f098d");
    EXPECT_EQ(MD5::Hash(test_data(0x4c)), "6710949ed8ae17c44fb77496bedcb2ab");
    EXPECT_EQ(MD5::Hash(test_data(0x4d)), "4a4c43373b9e40035e6e40cba227ce0b");
    EXPECT_EQ(MD5::Hash(test_data(0x4e)), "91977cbcc32cdeaec7a0fa24bb948d6a");
    EXPECT_EQ(MD5::Hash(test_data(0x4f)), "a6a0f1373cf3dbee116df2738d6f544d");

    EXPECT_EQ(MD5::Hash(test_data(0x50)), "761f6d007f6e5c64c8d161a5ced4e0aa");
    EXPECT_EQ(MD5::Hash(test_data(0x51)), "d44ea4d5a7074b88883a82f2b4cfbe67");
    EXPECT_EQ(MD5::Hash(test_data(0x52)), "3097eda5666e2b2723e8949fcff2f244");
    EXPECT_EQ(MD5::Hash(test_data(0x53)), "ab247a3d9bc600f594d5a6c50b80583f");
    EXPECT_EQ(MD5::Hash(test_data(0x54)), "b229430e3db2dfdd13aa1da1bac14d5c");
    EXPECT_EQ(MD5::Hash(test_data(0x55)), "befef62987c6dcdf24febd0bb7cd3678");
    EXPECT_EQ(MD5::Hash(test_data(0x56)), "bfc3e5c7c461500ff085a66548378e0e");
    EXPECT_EQ(MD5::Hash(test_data(0x57)), "a5712194537c75f0dd5a5ab3e9ebaf03");
    EXPECT_EQ(MD5::Hash(test_data(0x58)), "8daac097e9044b85b75999d6c3bccd24");
    EXPECT_EQ(MD5::Hash(test_data(0x59)), "b8124df21129685597c53a3f606ffd28");
    EXPECT_EQ(MD5::Hash(test_data(0x5a)), "8fbc4d795c22d958248582a8df7332ed");
    EXPECT_EQ(MD5::Hash(test_data(0x5b)), "36d217135db136b2bdf1617d7e9c79ce");
    EXPECT_EQ(MD5::Hash(test_data(0x5c)), "1b3e6271a3a4b663c509a1255027ca99");
    EXPECT_EQ(MD5::Hash(test_data(0x5d)), "a25f596574031ff9c34314c1b1f6bf34");
    EXPECT_EQ(MD5::Hash(test_data(0x5e)), "aca7017e5bb62bfdd5bbfded78c8987a");
    EXPECT_EQ(MD5::Hash(test_data(0x5f)), "8129e53a694add0560b1534b32fe5912");

    EXPECT_EQ(MD5::Hash(test_data(0x60)), "da0e48224106c7535a4cd8db2ac7b8e3");
    EXPECT_EQ(MD5::Hash(test_data(0x61)), "cbd4ace3d766d8e44f63e0de8f110f04");
    EXPECT_EQ(MD5::Hash(test_data(0x62)), "bdc17a0ef2777512cb402c90e9d13e31");
    EXPECT_EQ(MD5::Hash(test_data(0x63)), "47695ad6af968d6f1cdd2d8c5c87a466");
    EXPECT_EQ(MD5::Hash(test_data(0x64)), "7acedd1a84a4cfcb6e7a16003242945e");
    EXPECT_EQ(MD5::Hash(test_data(0x65)), "225489d3d073ac705f7b3ad358eabab2");
    EXPECT_EQ(MD5::Hash(test_data(0x66)), "301da87a7b2ec27514c3a2789d5dbe49");
    EXPECT_EQ(MD5::Hash(test_data(0x67)), "16222c503718f1420958133c330fe3f8");
    EXPECT_EQ(MD5::Hash(test_data(0x68)), "d778ce7f642aa23355948477da4cc11c");
    EXPECT_EQ(MD5::Hash(test_data(0x69)), "e873c37f8977e200a594b815e1a87ef3");
    EXPECT_EQ(MD5::Hash(test_data(0x6a)), "e8f8f41528d4f855d8fdf4055bbabe2f");
    EXPECT_EQ(MD5::Hash(test_data(0x6b)), "cacf3d3d1e7d21c97d265f64d9864b75");
    EXPECT_EQ(MD5::Hash(test_data(0x6c)), "6bf48f161eff9f7005bd6667f30a5c27");
    EXPECT_EQ(MD5::Hash(test_data(0x6d)), "42e7bb8e780b3b26616ecbcace81fa1a");
    EXPECT_EQ(MD5::Hash(test_data(0x6e)), "225afd8ec21f86f66211adf54afc2e86");
    EXPECT_EQ(MD5::Hash(test_data(0x6f)), "4fad3ab7d8546851ec1bb63ea7e6f5a8");

    EXPECT_EQ(MD5::Hash(test_data(0x70)), "d1fec2ac3715e791ca5f489f300381b3");
    EXPECT_EQ(MD5::Hash(test_data(0x71)), "f62807c995735b44699bb8179100ce87");
    EXPECT_EQ(MD5::Hash(test_data(0x72)), "54050b090344e3284f390806ff716371");
    EXPECT_EQ(MD5::Hash(test_data(0x73)), "50482241280543b88f7af3fc13d65c65");
    EXPECT_EQ(MD5::Hash(test_data(0x74)), "4c36f27d4786fe2fb8caac690b6d62f7");
    EXPECT_EQ(MD5::Hash(test_data(0x75)), "5a0edf0b97977ee5afb3d185b64fb610");
    EXPECT_EQ(MD5::Hash(test_data(0x76)), "4541055c6675b614d27c537c3bb15675");
    EXPECT_EQ(MD5::Hash(test_data(0x77)), "1c772251899a7ff007400b888d6b2042");
    EXPECT_EQ(MD5::Hash(test_data(0x78)), "b7ba1efc6022e9ed272f00b8831e26e6");
    EXPECT_EQ(MD5::Hash(test_data(0x79)), "b0b2d719a838db877b6d6571a39a1cdc");
    EXPECT_EQ(MD5::Hash(test_data(0x7a)), "800aa956ec16f603ecdba66c2dc6e4cf");
    EXPECT_EQ(MD5::Hash(test_data(0x7b)), "8827d2778287c58a242acd4c549beb31");
    EXPECT_EQ(MD5::Hash(test_data(0x7c)), "cfbc5aa0b61103c1a982d8927b26f575");
    EXPECT_EQ(MD5::Hash(test_data(0x7d)), "a1f5b691f74f566a2be1765731084f8a");
    EXPECT_EQ(MD5::Hash(test_data(0x7e)), "80749be03f5724fa4ca0aef8909379b7");
    EXPECT_EQ(MD5::Hash(test_data(0x7f)), "8402b21e7bc7906493bae0dac017f1f9");

    EXPECT_EQ(MD5::Hash(test_data(0x80)), "37eff01866ba3f538421b30b7cbefcac");
    EXPECT_EQ(MD5::Hash(test_data(0x81)), "46f986692847558fc38b0cece591c20f");
    EXPECT_EQ(MD5::Hash(test_data(0x82)), "7c05c285d0263c40a0437421b387a2a1");
    EXPECT_EQ(MD5::Hash(test_data(0x83)), "cc188799001d39bf0854be3426d93d51");
    EXPECT_EQ(MD5::Hash(test_data(0x84)), "5633ceac96819c2778e4ea5baa12b1cd");
    EXPECT_EQ(MD5::Hash(test_data(0x85)), "8b6831066bd6fa5d47714f2ea8bd137e");
    EXPECT_EQ(MD5::Hash(test_data(0x86)), "1783ae63d2db2973b3aedc5d66b33400");
    EXPECT_EQ(MD5::Hash(test_data(0x87)), "577b18536be8880747324fe72f73b4cb");
    EXPECT_EQ(MD5::Hash(test_data(0x88)), "e0d70f824895dedd2a6eff96b2496a08");
    EXPECT_EQ(MD5::Hash(test_data(0x89)), "d622abf62660ef4976d2c268257e38b8");
    EXPECT_EQ(MD5::Hash(test_data(0x8a)), "9a3909b356dd42783dff7b4092a8e25f");
    EXPECT_EQ(MD5::Hash(test_data(0x8b)), "05599be323d9f92e7a58f9bb42118737");
    EXPECT_EQ(MD5::Hash(test_data(0x8c)), "780c43f8f8caf48638dc4f2313158f76");
    EXPECT_EQ(MD5::Hash(test_data(0x8d)), "d5f6a198221af8fa64cb830c0311eed7");
    EXPECT_EQ(MD5::Hash(test_data(0x8e)), "94cde25ecffd3f73240f3d83ffd6b5e4");
    EXPECT_EQ(MD5::Hash(test_data(0x8f)), "ac4339e956f1a594b11b4be60ae35691");

    EXPECT_EQ(MD5::Hash(test_data(0x90)), "82254c4ffa7ad6a977d1cb52667cd772");
    EXPECT_EQ(MD5::Hash(test_data(0x91)), "58e2ca9acf732f5c4be9fb893a040b3c");
    EXPECT_EQ(MD5::Hash(test_data(0x92)), "b38cc9c297d3dce48f19e9722572372d");
    EXPECT_EQ(MD5::Hash(test_data(0x93)), "5f70fedb617e951ff5844d9812bd9b5c");
    EXPECT_EQ(MD5::Hash(test_data(0x94)), "8e723b5c1f9c524f3df345c6dfefcd34");
    EXPECT_EQ(MD5::Hash(test_data(0x95)), "745f520f26df966ab08f8629f464d9a4");
    EXPECT_EQ(MD5::Hash(test_data(0x96)), "b2ac0c745422d02bcd86d2ef3793fbb3");
    EXPECT_EQ(MD5::Hash(test_data(0x97)), "d44a13e4f5bc6067cb479cbe71621897");
    EXPECT_EQ(MD5::Hash(test_data(0x98)), "818e7209b35dcab2cf09bc348e1d40b4");
    EXPECT_EQ(MD5::Hash(test_data(0x99)), "7ab6b401d4020a282029f19275ae2da4");
    EXPECT_EQ(MD5::Hash(test_data(0x9a)), "54b51be0eade3f37428d2cdaaf41855f");
    EXPECT_EQ(MD5::Hash(test_data(0x9b)), "36c30f57eaf6a59fc16295c9441275f7");
    EXPECT_EQ(MD5::Hash(test_data(0x9c)), "e346e60198f7ad9e102340d59403cfbd");
    EXPECT_EQ(MD5::Hash(test_data(0x9d)), "affc7614e74ad844a0cb7357f5e63dcf");
    EXPECT_EQ(MD5::Hash(test_data(0x9e)), "aaac54364c782c27bcf85f4baa8a01d9");
    EXPECT_EQ(MD5::Hash(test_data(0x9f)), "08ddf1a1fe169ebadf020bf7608d09a8");

    EXPECT_EQ(MD5::Hash(test_data(0xa0)), "d548e64706a1ef6f712c4691224ae0c2");
    EXPECT_EQ(MD5::Hash(test_data(0xa1)), "cd5763f277ea4489a16f252f3a6e31ff");
    EXPECT_EQ(MD5::Hash(test_data(0xa2)), "56306ccd80b5bb5f6ad26575c3fd8b20");
    EXPECT_EQ(MD5::Hash(test_data(0xa3)), "59d431c923fb3986f6c88b72186ce7b4");
    EXPECT_EQ(MD5::Hash(test_data(0xa4)), "2287174326668bce993b2601e454cac1");
    EXPECT_EQ(MD5::Hash(test_data(0xa5)), "62228dcadd45303137ba761e625bf545");
    EXPECT_EQ(MD5::Hash(test_data(0xa6)), "2edf32cc58cf34ba4c0355480aa120a3");
    EXPECT_EQ(MD5::Hash(test_data(0xa7)), "ebf5e551cc4698fad12e23cd0a896cbe");
    EXPECT_EQ(MD5::Hash(test_data(0xa8)), "0ad9386009402849e45cadf2b3d81f76");
    EXPECT_EQ(MD5::Hash(test_data(0xa9)), "812b6bd7293cd7959985351476905c8b");
    EXPECT_EQ(MD5::Hash(test_data(0xaa)), "6f1890f1c51247e60bb8aeec48dc04d9");
    EXPECT_EQ(MD5::Hash(test_data(0xab)), "2f46ceaa9219e90e4367c1203a8279d3");
    EXPECT_EQ(MD5::Hash(test_data(0xac)), "2e1a8952e80678f0a971acf34d9323b2");
    EXPECT_EQ(MD5::Hash(test_data(0xad)), "6269ed8346f69f582f537e5ad54fc7e2");
    EXPECT_EQ(MD5::Hash(test_data(0xae)), "67000dc8749677f8b0a490e7830f90ce");
    EXPECT_EQ(MD5::Hash(test_data(0xaf)), "cc91c083f81039ea163e60143d75a017");

    EXPECT_EQ(MD5::Hash(test_data(0xb0)), "7b91f9e232fc5728e5753935b927a7f9");
    EXPECT_EQ(MD5::Hash(test_data(0xb1)), "fd64a907efaa9981aa90c402aeb9d5f7");
    EXPECT_EQ(MD5::Hash(test_data(0xb2)), "95677269f66b41c5e7d4bebfd6b76c21");
    EXPECT_EQ(MD5::Hash(test_data(0xb3)), "e3aca0de59a31fad3773dc1b56945885");
    EXPECT_EQ(MD5::Hash(test_data(0xb4)), "42b847ced4f9b84e8030add16b4589cd");
    EXPECT_EQ(MD5::Hash(test_data(0xb5)), "23ba18de73ec4c6575ed1be0d965e1ed");
    EXPECT_EQ(MD5::Hash(test_data(0xb6)), "9c470e7a268d605d73e7a4f418fa9852");
    EXPECT_EQ(MD5::Hash(test_data(0xb7)), "51999d289f5bbe579ce4a2224c7478d9");
    EXPECT_EQ(MD5::Hash(test_data(0xb8)), "76e4931d881a3c50d61b61b2f28f3152");
    EXPECT_EQ(MD5::Hash(test_data(0xb9)), "b5eb5787c150f5171912368a69a34281");
    EXPECT_EQ(MD5::Hash(test_data(0xba)), "e68a7e782091a126a3fd5129775bbdd3");
    EXPECT_EQ(MD5::Hash(test_data(0xbb)), "311da29ce1da0d6906209a55e92fb254");
    EXPECT_EQ(MD5::Hash(test_data(0xbc)), "636adfb00a8702ef427a2671d6c38281");
    EXPECT_EQ(MD5::Hash(test_data(0xbd)), "8e26d96042556f93b3ce25de6f084f1c");
    EXPECT_EQ(MD5::Hash(test_data(0xbe)), "e0b30eea7deb658061b82e7855690201");
    EXPECT_EQ(MD5::Hash(test_data(0xbf)), "4810b77b79c8a77c2f237265d565384e");

    EXPECT_EQ(MD5::Hash(test_data(0xc0)), "48599090c2176432f4fa671af1ccb6c2");
    EXPECT_EQ(MD5::Hash(test_data(0xc1)), "b4e66155a376e2cdb5e0892d3bee915d");
    EXPECT_EQ(MD5::Hash(test_data(0xc2)), "89b3411fba959e07c034acde928abc46");
    EXPECT_EQ(MD5::Hash(test_data(0xc3)), "59b867e2b86937e87c791987b3e408c7");
    EXPECT_EQ(MD5::Hash(test_data(0xc4)), "2f3d37c11076f00f027d96d8cd9cf943");
    EXPECT_EQ(MD5::Hash(test_data(0xc5)), "12e16b98ef3fd1e523911e9a020df66b");
    EXPECT_EQ(MD5::Hash(test_data(0xc6)), "7602fbac9420bd58c72a923d3dfc7687");
    EXPECT_EQ(MD5::Hash(test_data(0xc7)), "7c01c1c1599e517793f447ad02e83386");
    EXPECT_EQ(MD5::Hash(test_data(0xc8)), "fb7001d34b8e82c9b579be5005d5b0a5");
    EXPECT_EQ(MD5::Hash(test_data(0xc9)), "25f321363432ae94887c2af5e3854279");
    EXPECT_EQ(MD5::Hash(test_data(0xca)), "f08617537c59005b22009f1b24bb2389");
    EXPECT_EQ(MD5::Hash(test_data(0xcb)), "60ef17634ecbf55e24088b209c0f5bc0");
    EXPECT_EQ(MD5::Hash(test_data(0xcc)), "6b2ebd7a16a966ffd033e787a5b3e6b0");
    EXPECT_EQ(MD5::Hash(test_data(0xcd)), "16452ef6b8db3cf54bb8e9ad172a9e69");
    EXPECT_EQ(MD5::Hash(test_data(0xce)), "cebe2b709fb9019b68d36112081fecc5");
    EXPECT_EQ(MD5::Hash(test_data(0xcf)), "97043a2d56f045b0ac0f0e3be773b2a5");

    EXPECT_EQ(MD5::Hash(test_data(0xd0)), "adc63e4b0a7d9d544cfb60b71095835f");
    EXPECT_EQ(MD5::Hash(test_data(0xd1)), "4a4473504a27431eaebdef876dad3f4f");
    EXPECT_EQ(MD5::Hash(test_data(0xd2)), "d2375723a4fe55ed98972c7498ffbb6a");
    EXPECT_EQ(MD5::Hash(test_data(0xd3)), "5560730debc821c216afd556e7abac94");
    EXPECT_EQ(MD5::Hash(test_data(0xd4)), "a9b2636860f86567ea198831dcf18b85");
    EXPECT_EQ(MD5::Hash(test_data(0xd5)), "d3dc7a94f8587a60335043ec9a5cd68f");
    EXPECT_EQ(MD5::Hash(test_data(0xd6)), "e94835131e81cd5b336c80e8751c491a");
    EXPECT_EQ(MD5::Hash(test_data(0xd7)), "b23462fe71bcfa35f6f2d68719d0cf79");
    EXPECT_EQ(MD5::Hash(test_data(0xd8)), "e104421e96b2fa79b52e5b94ff684b83");
    EXPECT_EQ(MD5::Hash(test_data(0xd9)), "5c7b8bbc4e206e5add272475289edefd");
    EXPECT_EQ(MD5::Hash(test_data(0xda)), "19d38667addff9b35bc88532c5a7c89d");
    EXPECT_EQ(MD5::Hash(test_data(0xdb)), "163eb5680a41a0f978a14691a9a55b57");
    EXPECT_EQ(MD5::Hash(test_data(0xdc)), "609b36f7ca099027146f627d7c1b87c4");
    EXPECT_EQ(MD5::Hash(test_data(0xdd)), "c7ef5b63e448762b0389b4ea452734c7");
    EXPECT_EQ(MD5::Hash(test_data(0xde)), "00b0d05c1887db7935e510e15131b37d");
    EXPECT_EQ(MD5::Hash(test_data(0xdf)), "9b2cd2976df72cc25884f63de8651f65");

    EXPECT_EQ(MD5::Hash(test_data(0xe0)), "331e1699744701b65d8bdf6ea08bb5fb");
    EXPECT_EQ(MD5::Hash(test_data(0xe1)), "2da4f83d8cf7ad7f030130db966e70b4");
    EXPECT_EQ(MD5::Hash(test_data(0xe2)), "645d4483688c92376e38b9675f804710");
    EXPECT_EQ(MD5::Hash(test_data(0xe3)), "8a4f9211861999bb73278d003c58c01f");
    EXPECT_EQ(MD5::Hash(test_data(0xe4)), "dcbea204a5301705e3cb3bba49fd1c53");
    EXPECT_EQ(MD5::Hash(test_data(0xe5)), "d969cda70d04b412696f4ef0a5adff41");
    EXPECT_EQ(MD5::Hash(test_data(0xe6)), "11429183461be35415052fe04bfc8106");
    EXPECT_EQ(MD5::Hash(test_data(0xe7)), "eb9d2c88aae6c7b33aacba0336b58b17");
    EXPECT_EQ(MD5::Hash(test_data(0xe8)), "9264eab1fdefba47e3f89854be11069d");
    EXPECT_EQ(MD5::Hash(test_data(0xe9)), "bb916a43ce5883fcf0104a4d35f30253");
    EXPECT_EQ(MD5::Hash(test_data(0xea)), "b730e8b9f04e3ed3b073c99655293ec6");
    EXPECT_EQ(MD5::Hash(test_data(0xeb)), "9e45f084ce74240d33fa6c7fa48440d2");
    EXPECT_EQ(MD5::Hash(test_data(0xec)), "5a56a05fa7b73b6403530e89b024c3f5");
    EXPECT_EQ(MD5::Hash(test_data(0xed)), "09d54dc70fde38ec58858d5676801848");
    EXPECT_EQ(MD5::Hash(test_data(0xee)), "e316edfcf19ebec41d2b883b3ccc1117");
    EXPECT_EQ(MD5::Hash(test_data(0xef)), "4006f7d5ec5e2e49cb20bc0d8296439c");

    EXPECT_EQ(MD5::Hash(test_data(0xf0)), "ddabc96224d832fde27d53c83270c3f1");
    EXPECT_EQ(MD5::Hash(test_data(0xf1)), "267a256d457a3856bbfce6554c1566df");
    EXPECT_EQ(MD5::Hash(test_data(0xf2)), "8b00f7e89794bc5b2c4383cbb8f9bae5");
    EXPECT_EQ(MD5::Hash(test_data(0xf3)), "c6ed8882362bcbd5e25413ab6e85a325");
    EXPECT_EQ(MD5::Hash(test_data(0xf4)), "6f86c742ac261c3cea66286c1e2dfcee");
    EXPECT_EQ(MD5::Hash(test_data(0xf5)), "e375ff6bad4a9ad36baaccf22a7095bb");
    EXPECT_EQ(MD5::Hash(test_data(0xf6)), "f911bfe01c9aca4c144b31387c78aa92");
    EXPECT_EQ(MD5::Hash(test_data(0xf7)), "f220ef03645a47db8126f321de3c6012");
    EXPECT_EQ(MD5::Hash(test_data(0xf8)), "96c762e75475f86fac474622e4943839");
    EXPECT_EQ(MD5::Hash(test_data(0xf9)), "9b91849bde0bc07dae5b7c572cce9206");
    EXPECT_EQ(MD5::Hash(test_data(0xfa)), "d04120d0e8d4c6e61d6bb33cb6f14df5");
    EXPECT_EQ(MD5::Hash(test_data(0xfb)), "0a897617ec0dcb6efe8774fbcb4a9ac3");
    EXPECT_EQ(MD5::Hash(test_data(0xfc)), "15a155fa20962a0f21ffddb1e6695c43");
    EXPECT_EQ(MD5::Hash(test_data(0xfd)), "5089797486c967716d69b2ed0f9ba876");
    EXPECT_EQ(MD5::Hash(test_data(0xfe)), "7bdac450b9343317aa89895d4dda181e");
    EXPECT_EQ(MD5::Hash(test_data(0xff)), "11b7aaa64c413d2f0fccf893881c46a2");
}


TEST(md5sum, update) {

    std::string test_data {};
    test_data.resize(256 * 256);

    for (int i = 0; i < test_data.size(); ++i) {
        test_data[i] = i & 0xff;
    }

    for (int round = 1; round <= 256; ++round) {
        MD5 md5_obj;
        for (int i = 0; i < 256; ++i) {
            md5_obj.Update(test_data.data() + i * round, round);
        }
        EXPECT_EQ(md5_obj.Final().Digest(), MD5::Hash(test_data.data(), 256 * round));
    }

}