#pragma once

#include <string>

namespace md5 {

std::string md5sum(const std::string &dat);
std::string md5sum(const void *dat, size_t len);

std::string md5file(std::FILE *file);
std::string md5file(const char *filename);

} // namespace md5
