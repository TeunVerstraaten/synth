#ifndef __SINE__H_
#define __SINE__H_

#include "constants.h"
#include "synth.h"

#include <cmath>

class Sine : public Synth {

  public:
    Sine(float frequency, float amplitude) : Synth(frequency, amplitude) {
    }

    void fill_buffer() final {
        auto& left_buffer  = _buffer.left();
        auto& right_buffer = _buffer.right();

        for (unsigned i = 0; i < Buffer::BUFFER_SIZE; ++i) {
            left_buffer[i]  = _amplitude * std::sin(M_PI * _phase);
            right_buffer[i] = _amplitude * std::sin(M_PI * _phase);

            _phase += 2.0 * _frequency / SAMPLE_RATE;

            if (_phase >= 1) {
                _phase -= 2;
            }
        }
    }
};

#endif // __SINE__H_
