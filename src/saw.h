#ifndef __SAW__H_
#define __SAW__H_

#include "buffer.h"
#include "constants.h"
#include "synth.h"

class Saw : public Synth {
  public:
    Saw(float frequency, float amplitude) : Synth(frequency, amplitude) {
    }

    void fill_buffer() final {
        auto& left_buffer  = _buffer.left();
        auto& right_buffer = _buffer.right();

        for (unsigned i = 0; i < Buffer::BUFFER_SIZE; ++i) {
            left_buffer[i]  = _amplitude * _phase;
            right_buffer[i] = _amplitude * _phase;

            _phase += 2.0 * _frequency / SAMPLE_RATE;

            if (_phase >= 1) {
                _phase -= 2;
            }
        }
    }
};

#endif // __SAW__H_
