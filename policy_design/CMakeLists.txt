cmake_minimum_required(VERSION "3.5.1")

set(CMAKE_CXX_STANDARD	14)
project(HalloWorld)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

find_package(Boost 1.58.0 COMPONENTS filesystem)


add_executable(HalloWorld ${SOURCES})

  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(HalloWorld ${Boost_LIBRARIES})

