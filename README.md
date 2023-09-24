# md5sum

> Class to create MD5 checksum from file or string.

## Example

First clone the source code.

```bash
git clone https://github.com/dnomd343/md5sum.git
```

Then create `main.cc` and write the following demo code.

```c++
#include <string>
#include <iostream>
#include "md5sum.h"

using namespace md5;

int main() {
    std::string foo = "hello world";

    /* MD5 from std::string */
    std::cout << "md5sum: " << md5sum(foo) << std::endl;

    /* MD5 from c-string */
    std::cout << "md5sum: " << md5sum(foo.c_str(), foo.size()) << std::endl;

    /* MD5 from filename */
    std::cout << "md5file: " << md5file("md5sum/LICENSE") << std::endl;

    /* MD5 from opened file */
    std::FILE *file = std::fopen("md5sum/LICENSE", "rb");
    std::cout << "md5file: " << md5file(file) << std::endl;
    std::fclose(file);
}
```

Compile them and run.

```bash
> g++ -std=c++0x -I./md5sum -o demo main.cc md5sum/*.cc
> ./demo
md5sum: 5eb63bbbe01eeed093cb22bb8f5acdc3
md5sum: 5eb63bbbe01eeed093cb22bb8f5acdc3
md5file: 4ab93db71092d8b54266f83575c1b9e1
md5file: 4ab93db71092d8b54266f83575c1b9e1
```

A more elegant approach is to use cmake to compile, create `CMakeLists.txt` and write the following content.

```cmake
cmake_minimum_required(VERSION 3.5)
project(demo LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

include_directories(md5sum)
add_subdirectory(md5sum EXCLUDE_FROM_ALL)

add_executable(demo main.cc)
target_link_libraries(demo md5sum)
```

Using the following command to build and run.

```bash
> cmake -B ./cmake-build/
-- The CXX compiler identification is AppleClang 15.0.0.15000040
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: ...
> cmake --build ./cmake-build/
[ 20%] Building CXX object md5sum/CMakeFiles/md5sum.dir/md5.cc.o
[ 40%] Building CXX object md5sum/CMakeFiles/md5sum.dir/md5_impl.cc.o
[ 60%] Linking CXX static library libmd5sum.a
[ 60%] Built target md5sum
[ 80%] Building CXX object CMakeFiles/demo.dir/main.cc.o
[100%] Linking CXX executable demo
[100%] Built target demo
> ./cmake-build/demo
md5sum: 5eb63bbbe01eeed093cb22bb8f5acdc3
md5sum: 5eb63bbbe01eeed093cb22bb8f5acdc3
md5file: 4ab93db71092d8b54266f83575c1b9e1
md5file: 4ab93db71092d8b54266f83575c1b9e1
```

## License

MIT ©2021 [@ulwanski](https://github.com/ulwanski)

MIT ©2023 [@dnomd343](https://github.com/dnomd343)
