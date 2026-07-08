#include <alsa/asoundlib.h>
#include <cmath>
#include <cstdint>
#include <iostream>

constexpr unsigned SAMPLE_RATE = 48000;
constexpr float    FREQUENCY   = 440.0f;
constexpr float    AMPLITUDE   = 0.2f;
constexpr unsigned BUFFER_SIZE = 512;

int main() {
    snd_pcm_t* pcm;

    int err = snd_pcm_open(&pcm, "default", SND_PCM_STREAM_PLAYBACK, 0);

    if (err < 0) {
        std::cerr << "Failed to open ALSA device: " << snd_strerror(err) << "\n";
        return 1;
    }

    err = snd_pcm_set_params(pcm,
                             SND_PCM_FORMAT_FLOAT_LE, // 32-bit float samples
                             SND_PCM_ACCESS_RW_INTERLEAVED,
                             1, // mono
                             SAMPLE_RATE,
                             1,     // allow resampling
                             500000 // 0.5 sec latency
    );

    if (err < 0) {
        std::cerr << "Failed to configure device: " << snd_strerror(err) << "\n";
        return 1;
    }

    float buffer[BUFFER_SIZE];

    double phase          = 0.0;
    double phaseIncrement = 2.0 * M_PI * FREQUENCY / SAMPLE_RATE;

    while (true) {

        for (unsigned i = 0; i < BUFFER_SIZE; ++i) {
            buffer[i] = AMPLITUDE * std::sin(phase);

            phase += phaseIncrement;

            if (phase >= 2.0 * M_PI)
                phase -= 2.0 * M_PI;
        }

        snd_pcm_sframes_t frames = snd_pcm_writei(pcm, buffer, BUFFER_SIZE);

        if (frames < 0) {
            frames = snd_pcm_recover(pcm, frames, 0);
        }

        if (frames < 0) {
            std::cerr << "Write failed: " << snd_strerror(frames) << "\n";
            break;
        }
    }

    snd_pcm_close(pcm);
}
