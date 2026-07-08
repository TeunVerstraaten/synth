#ifndef __BUFFER__H_
#define __BUFFER__H_

#include <array>

class Buffer {
  public:
    static constexpr unsigned BUFFER_SIZE = 1024;

  private:
    std::array<float, BUFFER_SIZE> _left;
    std::array<float, BUFFER_SIZE> _right;

  public:
    const std::array<float, BUFFER_SIZE>& left() const;
    const std::array<float, BUFFER_SIZE>& right() const;
    std::array<float, BUFFER_SIZE>&       left();
    std::array<float, BUFFER_SIZE>&       right();
    void                                  set_zero();
};

#endif // __BUFFER__H_
