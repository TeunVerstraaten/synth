#include "src/buffer.h"
#include "src/pcm.h"
#include "src/saw.h"
#include "src/sine.h"
#include "src/synth.h"

#include <algorithm>
#include <alsa/asoundlib.h>
#include <memory>
#include <vector>

int main() {
    Pcm pcm;

    Buffer buffer;

    std::vector<std::unique_ptr<Synth>> saws;

    for (size_t i = 0; i != 5; ++i) {
        saws.emplace_back(new Saw(440.0 + (static_cast<float>(i) / 8.4), 0.1));
    }

    while (true) {
        buffer.set_zero();

        std::ranges::for_each(saws, [&buffer](auto& synth) {
            synth->fill_buffer();
            synth->add_to_buffer(buffer);
        });

        pcm.write_buffer(buffer);
    }
}
