cmake_minimum_required(VERSION 3.16)

project(SimpleSynth LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ALSA REQUIRED alsa)

add_executable(synth
    main.cpp src/pcm.cpp
)

target_include_directories(synth PRIVATE
    ${ALSA_INCLUDE_DIRS}
)

target_link_directories(synth PRIVATE
    ${ALSA_LIBRARY_DIRS}
)

target_link_libraries(synth PRIVATE
    ${ALSA_LIBRARIES}
)

target_compile_options(synth PRIVATE
    ${ALSA_CFLAGS_OTHER}
)
