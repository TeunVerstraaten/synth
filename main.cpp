#include "src/constants.h"
#include "src/pcm.h"
#include "src/saw.h"
#include "src/sine.h"

#include <alsa/asoundlib.h>
#include <cassert>
#include <cmath>

int main() {
    Pcm pcm;

    float buffer[BUFFER_SIZE];
    Saw   sine{440.0, 1.0};

    while (true) {
        sine.fill_buffer(buffer, BUFFER_SIZE);

        pcm.write(buffer, BUFFER_SIZE);
    }
}
