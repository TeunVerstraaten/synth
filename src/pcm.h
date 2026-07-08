#ifndef __PCM__H_
#define __PCM__H_

#include "buffer.h"
#include "constants.h"

#include <alsa/asoundlib.h>
#include <array>
#include <cassert>

class Pcm {
    snd_pcm_t* pcm;

  public:
    Pcm();
    ~Pcm();
    void write(Buffer& buffer);
};
#endif // __PCM__H_
