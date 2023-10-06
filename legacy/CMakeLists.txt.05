cmake_minimum_required(VERSION 3.10)
# Define your project and languages used
project(
  RaylibEngine
  VERSION 1.0
  LANGUAGES CXX)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_subdirectory(vcpkg_installed/arm64-osx) Set the build type if not provided
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Recursive find all files and add them to the project
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Enable the compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Instead of using vcpkg's toolchain file for finding packages, we'll manually
# specify paths to headers and libraries.

# Manually specify raylib's header and library paths
include_directories(${CMAKE_SOURCE_DIR}/vcpkg_installed/arm64-osx/include/)
link_directories(${CMAKE_SOURCE_DIR}/vcpkg_installed/arm64-osx/lib/)

# Define sources for your project
set(SOURCES src/main.cpp) # Adjust this if you have other source files

# Add the executable target add_executable(${PROJECT_NAME} ${SOURCES})
add_executable(main ${SOURCES})

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}) # Link the libraries to the
                                                   # target

# Enable the compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if(APPLE)
  # Headers [optional]
  target_include_directories(main PRIVATE) # Link the libraries
  target_link_libraries(main PRIVATE raylib)
  set(CMAKE_CXX_FLAGS_DEBUG
      "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g -lGL -lm -lpthread -ldl -lX11 -lglfw3 -framework Cocoa -framework IOKit -framework CoreFoundation "
  )

  set(CMAKE_CXX_FLAGS_RELEASE
      "${CMAKE_CXX_FLAGS_RELEASE} -O3 -lGL -lm -lpthread -ldl -lX11 -lglfw3 -framework Cocoa -framework IOKit -framework CoreFoundation"
  )
endif()
#
