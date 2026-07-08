#ifndef __SYNTH__H_
#define __SYNTH__H_

#include "constants.h"

#include <array>
#include <cstddef>

class Synth {

  protected:
    std::array<float, BUFFER_SIZE> _buffer;

  public:
    virtual void fill_buffer() = 0;
    virtual ~Synth()           = default;

    const std::array<float, BUFFER_SIZE> buffer() const {
        return _buffer;
    }
};

#endif // __SYNTH__H_
