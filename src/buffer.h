#ifndef __BUFFER__H_
#define __BUFFER__H_

#include "constants.h"

#include <algorithm>
#include <array>

class Buffer {
    std::array<float, BUFFER_SIZE> _left;
    std::array<float, BUFFER_SIZE> _right;

  public:
    constexpr static size_t samples() {
        return BUFFER_SIZE;
    }

    const std::array<float, BUFFER_SIZE>& left() const {
        return _left;
    }

    const std::array<float, BUFFER_SIZE>& right() const {
        return _right;
    }

    std::array<float, BUFFER_SIZE>& left() {
        return _left;
    }

    std::array<float, BUFFER_SIZE>& right() {
        return _right;
    }

    void set_zero() {
        std::ranges::for_each(_right, [](auto& s) { s = 0; });
        std::ranges::for_each(_left, [](auto& s) { s = 0; });
    }
};

#endif // __BUFFER__H_
