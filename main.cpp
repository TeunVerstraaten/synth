#include "src/buffer.h"
#include "src/constants.h"
#include "src/pcm.h"
#include "src/saw.h"
#include "src/sine.h"
#include "src/synth.h"

#include <algorithm>
#include <alsa/asoundlib.h>
#include <array>
#include <cassert>
#include <cmath>
#include <memory>
#include <vector>

int main() {
    Pcm pcm;

    Buffer buffer;

    std::vector<std::unique_ptr<Synth>> saws;

    for (size_t i = 0; i != 5; ++i) {
        saws.emplace_back(new Saw(0.1 * 440.0 + (static_cast<float>(i) / 6.4), 0.1));
    }

    while (true) {
        buffer.set_zero();

        std::ranges::for_each(saws, [&buffer](auto& synth) {
            synth->fill_buffer();
            synth->add_to_buffer(buffer);
        });

        pcm.write(buffer);
    }
}
