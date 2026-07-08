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
        for (unsigned i = 0; i < _buffer.size(); ++i) {
            _buffer[i] = _amplitude * _phase;

            _phase += _d_phase;

            if (_phase >= 1) {
                _phase -= 2;
            }
        }
    }
};

#endif // __SAW__H_
