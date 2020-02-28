cmake_minimum_required(VERSION 3.15)
project(mp3encoder)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")


set(CMAKE_CXX_STANDARD 17)
link_libraries(stdc++fs)
link_libraries(pthread)
add_executable(mp3encoder main.cpp ${SOURCES} src/browser/wav_browser.cpp
        src/encoder/lame_encoder.cpp
        src/encoder/mp3_encoder.cpp
        src/browser/directory_browser.cpp)