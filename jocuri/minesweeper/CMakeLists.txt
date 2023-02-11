cmake_minimum_required(VERSION 3.21)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/images" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled2_264 main.cpp)


target_link_libraries(
        untitled2_264
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
)