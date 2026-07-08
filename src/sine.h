#ifndef __SINE__H_
#define __SINE__H_

#include "constants.h"
#include "synth.h"

#include <cmath>

class Sine : public Synth {
    double _amplitude;
    double _phase;
    double _d_phase;

  public:
    Sine(float frequency, double amplitude) : _amplitude(amplitude), _phase(0), _d_phase(2.0 * M_PI * frequency / SAMPLE_RATE) {
    }

    void fill_buffer() final {
        for (unsigned i = 0; i < _buffer.size(); ++i) {
            _buffer[i] = _amplitude * std::sin(_phase);

            _phase += _d_phase;

            if (_phase >= 2.0 * M_PI) {
                _phase -= 2.0 * M_PI;
            }
        }
    }
};

#endif // __SINE__H_
