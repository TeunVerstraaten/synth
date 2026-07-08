#ifndef __SAW__H_
#define __SAW__H_

#include "constants.h"
#include "synth.h"

#include <cmath>

class Saw : public Synth {
    double _amplitude;
    double _phase;
    double _d_phase;

  public:
    Saw(float frequency, double amplitude) : _amplitude(amplitude), _phase(0), _d_phase(2.0 * frequency / SAMPLE_RATE) {
    }

    void fill_buffer() final {
        auto& left_buffer  = _buffer.left();
        auto& right_buffer = _buffer.right();

        for (unsigned i = 0; i < _buffer.samples(); ++i) {
            left_buffer[i]  = _amplitude * _phase;
            right_buffer[i] = _amplitude * _phase;

            _phase += _d_phase;

            if (_phase >= 1) {
                _phase -= 2;
            }
        }
    }
};

#endif // __SAW__H_
