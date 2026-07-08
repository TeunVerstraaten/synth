#include "pcm.h"

#include "constants.h"

#include <iostream>

Pcm::Pcm() {
    int err = snd_pcm_open(&pcm, "default", SND_PCM_STREAM_PLAYBACK, 0);
    assert(err >= 0);
    err = snd_pcm_set_params(pcm, SND_PCM_FORMAT_FLOAT_LE, SND_PCM_ACCESS_RW_NONINTERLEAVED, 2, SAMPLE_RATE, 1, 500000);
    assert(err >= 0);
}

Pcm::~Pcm() {
    snd_pcm_close(pcm);
}

void Pcm::write(Buffer& buffer) {

    void* buffer_ptrs[] = {buffer.left().data(), buffer.right().data()};

    snd_pcm_sframes_t frames = snd_pcm_writen(pcm, buffer_ptrs, BUFFER_SIZE);

    if (frames < 0) {
        frames = snd_pcm_recover(pcm, frames, 0);
    }

    assert(frames >= 0);
}
