cmake_minimum_required(VERSION 3.16)
project(VocabsEasy)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


file(GLOB source_files
        "vocabs_app/*"
        "vocabs_ui/*"
        )

include_directories(vocabs_app)
include_directories(vocabs_ui)
find_package(Qt5 COMPONENTS Core  Gui Widgets REQUIRED)


add_executable(VocabsEasy main.cpp ${source_files} vocabs_ui/main_window.h vocabs_ui/verb_window.h)
target_link_libraries(VocabsEasy Qt::Core Qt::Gui Qt::Widgets)

# copy ial configuration to output bin
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resource DESTINATION ${CMAKE_BINARY_DIR})
