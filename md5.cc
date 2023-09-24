#include "md5sum.h"
#include "md5def.h"

namespace md5 {

static char hb2hex(uint8_t hb) {
    hb &= 0xF;
    return char(hb < 10 ? hb + '0' : hb - 10 + 'a');
}

std::string md5sum(const std::string &dat) {
    return md5sum(dat.c_str(), dat.length());
}

std::string md5sum(const void *dat, size_t len) {
    uint8_t out[16];
    md5_bin(dat, len, out);

    std::string res;
    for (auto x : out) {
        res.push_back(hb2hex(x >> 4));
        res.push_back(hb2hex(x));
    }
    return res;
}

std::string md5file(const char *filename) {
	std::FILE *file = std::fopen(filename, "rb");
	std::string res = md5file(file);
	std::fclose(file);
	return res;
}

std::string md5file(std::FILE *file) {
	MD5_CTX c;
    md5_init(&c);

    size_t len;
	uint8_t out[16];
    char buff[BUFSIZ];
	while ((len = std::fread(buff, sizeof(char), BUFSIZ, file)) > 0) {
		md5_update(&c, buff, len);
	}
	md5_final(out, &c);

	std::string res;
	for (auto x : out) {
        res.push_back(hb2hex(x >> 4));
        res.push_back(hb2hex(x));
    }
	return res;
}

} // namespace md5
