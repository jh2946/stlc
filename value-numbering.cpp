#include <iostream>
#include <vector>

uint64_t depair(std::pair<uint64_t, uint64_t> in) {
    uint64_t k = in.first + in.second;
    return (k * (k+3) / 2) - in.second;
}

std::pair<uint64_t, uint64_t> pair(uint64_t n) {
    uint64_t m = 1;
    while ((2*m-1)*(2*m-1) <= 8*n+1) m <<= 1;
    m >>= 1;
    for (uint64_t b = m >> 1; b != 0; b >>= 1) {
        uint64_t m_1 = m | b;
        if ((2*m_1-1) * (2*m_1-1) <= 8*n+1) m = m_1;
    }
    uint64_t j = m * (m+1) / 2 - n;
    return {m-j, j-1};
}
