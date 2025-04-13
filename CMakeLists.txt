cmake_minimum_required(VERSION 3.20)
project(drawtest)

# configure SDL3
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)

add_subdirectory(sdl3)

add_executable(drawtest_a WIN32
    drawtest.c)
target_compile_definitions(drawtest_a PRIVATE PATTERN_A)

add_executable(drawtest_b WIN32
    drawtest.c)
target_compile_definitions(drawtest_b PRIVATE PATTERN_B)

target_link_libraries(drawtest_a SDL3::SDL3-static)
target_link_libraries(drawtest_b SDL3::SDL3-static)
