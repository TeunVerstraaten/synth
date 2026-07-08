#include "src/constants.h"
#include "src/pcm.h"
#include "src/saw.h"
#include "src/sine.h"

#include <algorithm>
#include <alsa/asoundlib.h>
#include <array>
#include <cassert>
#include <cmath>
#include <memory>
#include <vector>

int main() {
    Pcm pcm;

    std::array<float, BUFFER_SIZE> buffer;

    std::vector<std::unique_ptr<Synth>> saws;

    for (size_t i = 0; i != 5; ++i) {
        saws.emplace_back(new Saw(0.1 * 440.0 + (static_cast<float>(i) / 6.4), 0.1));
    }

    while (true) {
        std::ranges::for_each(buffer, [](auto& s) { s = 0; });

        std::ranges::for_each(saws, [&buffer](auto& saw) {
            saw->fill_buffer();
            const auto& synth_buffer = saw->buffer();
            for (size_t i = 0; i != BUFFER_SIZE; ++i) {
                buffer[i] += synth_buffer[i];
            }
        });

        pcm.write(buffer.data(), BUFFER_SIZE);
    }
}
