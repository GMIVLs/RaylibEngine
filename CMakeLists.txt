cmake_minimum_required(VERSION 3.5)
project(RayLibEngine CXX)
# Set C++ standard (optional)
set(CMAKE_CXX_STANDARD 17)

# Source files for your project
set(SOURCES src/main.cpp) # Adjust this to point to your source files

# Set the build type if not provided
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Setting my compling command for clangd language server, offer jump to
# definition,
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Include directories
#- Locally installed for our project
#- run vcpkg install at project root directory
include_directories($ENV{PROJECT_DIR}/vcpkg_installed/arm64-osx/include/)
link_directories($ENV{PROJECT_DIR}/vcpkg_installed/arm64-osx/lib/)
# Using Emacs, it doesn't understand the environment variables.
# include_directories(/Users/gmbp/Desktop/devCode/cppDev/RaylibEngine/vcpkg_installed/arm64-osx/include/)
# link_directories(/Users/gmbp/Desktop/devCode/cppDev/RaylibEngine/vcpkg_installed/arm64-osx/lib/)
# Create the executable
add_executable(main ${SOURCES})

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})
# Necessary libraries for building for macOS M1 architecture
# find_library(COREFOUNDATION_LIBRARY CoreFoundation)
# find_library(COREGRAPHICS_LIBRARY CoreGraphics) find_library(APPKIT_LIBRARY
# AppKit) find_library(IOKIT_LIBRARY IOKit)

# Headers [optional]
target_include_directories(
  main PRIVATE $ENV{PROJECT_DIR}/vcpkg_installed/arm64-osx/include/)
# Link the libraries
target_link_libraries(main PRIVATE raylib)
# ${COREFOUNDATION_LIBRARY} ${COREGRAPHICS_LIBRARY} ${APPKIT_LIBRARY}
# ${IOKIT_LIBRARY} ) # notice raylib has to be at the end, since it needs APPKIT

set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g -lGL -lm -lpthread -ldl -lX11 -lglfw3 -framework Cocoa -framework IOKit -framework CoreFoundation " # -lrt
)
# You can add (-Werror), but it will make the complier more restrictive.
set(CMAKE_CXX_FLAGS_RELEASE
    "${CMAKE_CXX_FLAGS_RELEASE} -O3 -lGL -lm -lpthread -ldl -lX11 -lglfw3 -framework Cocoa -framework IOKit -framework CoreFoundation"
)
