#ifndef __SYNTH__H_
#define __SYNTH__H_

#include <cstddef>

class Synth {
  public:
    virtual void fill_buffer(float* buffer, size_t buffer_size) = 0;
};

#endif // __SYNTH__H_
