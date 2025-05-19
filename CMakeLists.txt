cmake_minimum_required(VERSION 3.16)
project(battleships)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

set(SDLIMAGE_VENDORED ON)
set(SDLIMAGE_AVIF OFF)	# disable formats we don't use to make the build faster and smaller.
set(SDLIMAGE_BMP OFF)
set(SDLIMAGE_JPEG OFF)
set(SDLIMAGE_TIF OFF)
set(SDLIMAGE_WEBP OFF)
add_subdirectory(vendored/SDL_image EXCLUDE_FROM_ALL)


# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create game executable target
add_executable(
    battleships
    WIN32
    src/game.cxx
    src/main.cxx
    src/main_scene.cxx
    src/scenes.cxx
    src/texture.cxx
)

# Link to the actual SDL3 library.
target_link_libraries(battleships PUBLIC SDL3_image::SDL3_image SDL3::SDL3)

# Copy assets to the build directory
add_custom_command(
    TARGET battleships
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/$<CONFIGURATION>/assets
)

# EOF
