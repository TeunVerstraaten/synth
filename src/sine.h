#ifndef __SINE__H_
#define __SINE__H_

#include "constants.h"
#include "synth.h"

#include <cmath>

class Sine : public Synth {
    double _frequency;
    double _amplitude;
    double _phase;
    double _phaseIncrement;

  public:
    Sine(float frequency, double amplitude)
        : _frequency(frequency), _amplitude(amplitude), _phase(0), _phaseIncrement(2.0 * M_PI * frequency / SAMPLE_RATE) {
    }

    void fill_buffer(float* buffer, size_t buffer_size) final {
        for (unsigned i = 0; i < buffer_size; ++i) {
            buffer[i] = _amplitude * std::sin(_phase);

            _phase += _phaseIncrement;

            if (_phase >= 2.0 * M_PI) {
                _phase -= 2.0 * M_PI;
            }
        }
    }
};

#endif // __SINE__H_
