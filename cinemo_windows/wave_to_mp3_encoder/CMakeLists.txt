cmake_minimum_required(VERSION 3.15)
project(mp3encoder)
include_directories(include)

file(GLOB SOURCES "src/*.cpp")


set(CMAKE_CXX_STANDARD 17)
link_libraries(pthread)
message(${CMAKE_SYSTEM_NAME})
if(CYGWIN)
    message(STATUS ">>> Not Linux")
    # stuff that should happen not on Linux
    link_libraries(/usr/lib/libmp3lame.dll.a)
else()
    message(STATUS ">>> Linux")
    link_libraries(/usr/lib/x86_64-linux-gnu/libmp3lame.a)
    # linux stuff here
endif()

add_executable(mp3encoder main.cpp ${SOURCES} src/browser/wav_browser.cpp
        src/encoder/lame_encoder.cpp
        src/encoder/mp3_encoder.cpp
        src/browser/directory_browser.cpp  src/encoder/wav_header.cpp)
