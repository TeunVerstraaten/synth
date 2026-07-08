#ifndef __SAW__H_
#define __SAW__H_

#include "constants.h"
#include "synth.h"

#include <cmath>

class Saw : public Synth {
    double _frequency;
    double _amplitude;
    double _phase;
    double _phaseIncrement;

  public:
    Saw(float frequency, double amplitude)
        : _frequency(frequency), _amplitude(amplitude), _phase(0), _phaseIncrement(2.0 * M_PI * frequency / SAMPLE_RATE) {
    }

    void fill_buffer(float* buffer, size_t buffer_size) final {
        for (unsigned i = 0; i < buffer_size; ++i) {
            buffer[i] = _amplitude * _phase / 2.0 / M_PI;

            _phase += _phaseIncrement;

            if (_phase >= 2.0 * M_PI) {
                _phase -= 2.0 * M_PI;
            }
        }
    }
};

#endif // __SAW__H_
