#include "src/constants.h"
#include "src/pcm.h"

#include <alsa/asoundlib.h>
#include <cassert>
#include <cmath>

int main() {
    Pcm pcm;

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

        pcm.write(buffer, BUFFER_SIZE);
    }
}
