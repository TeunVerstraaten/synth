#ifndef __SYNTH__H_
#define __SYNTH__H_

#include "buffer.h"
#include "constants.h"

#include <array>
#include <cstddef>

class Synth {

  protected:
    Buffer _buffer;

  public:
    virtual void fill_buffer() = 0;
    virtual ~Synth()           = default;

    void add_to_buffer(Buffer& target) {
        auto& left_buffer  = _buffer.left();
        auto& right_buffer = _buffer.right();
        auto& left_target  = target.left();
        auto& right_target = target.right();

        for (size_t i = 0; i != _buffer.samples(); ++i) {
            left_target[i] += left_buffer[i];
            right_target[i] += right_buffer[i];
        }
    }

    // const std::array<float, BUFFER_SIZE> buffer() const {
    //     return _buffer;
    // }
};

#endif // __SYNTH__H_
