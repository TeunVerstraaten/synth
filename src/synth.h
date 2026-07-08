#ifndef __SYNTH__H_
#define __SYNTH__H_

#include "buffer.h"
#include "constants.h"

#include <cstddef>

class Synth {
  protected:
    Buffer _buffer;
    double _frequency;
    double _amplitude;
    double _phase;

  public:
    Synth(float frequency, float amplitude) : _frequency(frequency), _amplitude(amplitude), _phase(0) {
    }
    virtual ~Synth() = default;

    virtual void fill_buffer() = 0;

    void add_to_buffer(Buffer& target) {
        auto& left_buffer  = _buffer.left();
        auto& right_buffer = _buffer.right();
        auto& left_target  = target.left();
        auto& right_target = target.right();

        for (size_t i = 0; i != Buffer::BUFFER_SIZE; ++i) {
            left_target[i] += left_buffer[i];
            right_target[i] += right_buffer[i];
        }
    }
};

#endif // __SYNTH__H_
