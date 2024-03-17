#include <iostream>

#include "md5_core.h"

std::string test_data() {
    char data[64];
    for (char i = 0; i < 64; ++i) {
        data[i] = i;
    }
    return {data, data + 64};
}

void dump_ctx(const md5::md5_ctx *c) {
    std::cout << std::hex << c->A << std::endl;
    std::cout << std::hex << c->B << std::endl;
    std::cout << std::hex << c->C << std::endl;
    std::cout << std::hex << c->D << std::endl;
    std::cout << std::dec << c->size << std::endl;
}

int main() {
    auto data = test_data() + test_data() + test_data() + test_data();

    md5::md5_ctx c;
    dump_ctx(&c);

    // md5::md5_update(&c, data.c_str(), data.size());
    // md5::md5_update(&c, data.c_str(), data.size());
    // dump_ctx(&c);

    // md5::md5_reset(&c);
    // md5::md5_update(&c, data.c_str(), data.size());
    // md5::md5_update(&c, data.c_str(), data.size());
    // dump_ctx(&c);

    md5::md5_final(&c, data.c_str(), 0);
    dump_ctx(&c);

    md5::md5_reset(&c);
    md5::md5_final(&c, data.c_str(), data.size());
    dump_ctx(&c);
}
