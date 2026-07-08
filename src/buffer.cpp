#include "buffer.h"

#include <algorithm>

const std::array<float, Buffer::BUFFER_SIZE>& Buffer::left() const {
    return _left;
}

const std::array<float, Buffer::BUFFER_SIZE>& Buffer::right() const {
    return _right;
}

std::array<float, Buffer::BUFFER_SIZE>& Buffer::left() {
    return _left;
}

std::array<float, Buffer::BUFFER_SIZE>& Buffer::right() {
    return _right;
}

void Buffer::set_zero() {
    std::ranges::for_each(_right, [](auto& s) { s = 0; });
    std::ranges::for_each(_left, [](auto& s) { s = 0; });
}
