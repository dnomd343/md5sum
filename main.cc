#include <iostream>
#include "md5sum.h"

int main() {
    auto ret = md5sum("dnomd343");
    std::cout << ret << std::endl;

    auto val = md5file("/Users/jucong.lin/klotski/third_party/md5sum/343.txt");
    std::cout << val << std::endl;
}
