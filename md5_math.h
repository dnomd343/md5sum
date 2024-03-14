#pragma once

#include <cmath>

namespace md5::math {

constexpr double PI = 3.141592653589793238462643L;

consteval double pow(double x, int n) {
    double res = 1;
    for (int i = 0; i < n; ++i) {
        res *= x;
    }
    return res;
}

consteval double factorial(int n) {
    double res = 1;
    for (int i = 2 ; i <= n ; ++i) {
        res *= i;
    }
    return res;
}

/// Calculate sin(x) value with Maclaurin series.
consteval double sin_core(double x) {
    double res = x;
    for (int i = 1; i < 80; ++i) {
        const int n = i * 2 + 1;
        const int sign = (i & 1) ? -1 : 1;
        res += sign * pow(x, n) / factorial(n);
    }
    return res;
}

/// Calculate the sin(x) value in radians.
consteval double sin(double x) {
    x = std::fmod(x, 2 * PI); // -2PI < x < 2PI

    if (std::abs(x) > PI) {
        x -= ((x > 0) ? 2 : -2) * PI; // -PI < x < PI
    }

    if (std::abs(x) > PI / 2) {
        x = ((x > 0) ? 1 : -1) * PI - x; // -PI / 2 < x < PI / 2
    }
    return sin_core(x);
}

} // namespace md5::math
