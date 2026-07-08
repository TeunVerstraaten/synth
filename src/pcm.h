#ifndef __PCM__H_
#define __PCM__H_

#include "constants.h"

#include <alsa/asoundlib.h>
#include <cassert>

class Pcm {
    snd_pcm_t* pcm;

  public:
    Pcm();
    ~Pcm();
    void write(float* buffer, size_t buffer_size);
};
#endif // __PCM__H_
