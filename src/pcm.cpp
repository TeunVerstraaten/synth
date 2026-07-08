#include "pcm.h"

Pcm::Pcm() {
    int err = snd_pcm_open(&pcm, "default", SND_PCM_STREAM_PLAYBACK, 0);
    assert(err >= 0);
    err = snd_pcm_set_params(pcm,
                             SND_PCM_FORMAT_FLOAT_LE, // 32-bit float samples
                             SND_PCM_ACCESS_RW_INTERLEAVED,
                             1, // mono
                             SAMPLE_RATE,
                             1,     // allow resampling
                             500000 // 0.5 sec latency
    );
    assert(err >= 0);
}

Pcm::~Pcm() {
    snd_pcm_close(pcm);
}

void Pcm::write(float* buffer, size_t buffer_size) {
    snd_pcm_sframes_t frames = snd_pcm_writei(pcm, buffer, BUFFER_SIZE);

    if (frames < 0) {
        frames = snd_pcm_recover(pcm, frames, 0);
    }

    assert(frames >= 0);
}
