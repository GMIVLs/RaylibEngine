cmake_minimum_required(VERSION 3.10)
# Define your project and languages used
project(
  RaylibEngine
  VERSION 1.0
  LANGUAGES CXX)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Enable the compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Recursive find all files and add them to the project
file(GLOB_RECURSE SOURCES "src/*.cpp")

# add_subdirectory(vcpkg_installed/arm64-osx) Set the build type if not provided
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Include the vcpkg toolchain file
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE
      "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "Defined our vcpkg library ... ")
endif()

# Instead of using vcpkg's toolchain file for finding packages, we'll manually
# specify paths to headers and libraries.

# Finding the packages base on globally installed libraries at ~/vcpkg/installed
find_package(glfw3 CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)

set(SOURCES src/main.cpp) # Adjust this if you have other source files

# Add the executable target add_executable(${PROJECT_NAME} ${SOURCES})
add_executable(main ${SOURCES})

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}) # Link the libraries to the
                                                   # target
# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if(APPLE)
  # Adding Sanitize
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
  # Headers [optional] target_include_directories(main PRIVATE glfw raylib) Link
  # the libraries
  target_link_libraries(main PRIVATE glfw raylib)

  set(CMAKE_CXX_FLAGS_DEBUG
      "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g -lGL -lm -lpthread -ldl -lX11 " # -lrt
                                                                                 # -lglfw3
                                                                                 # -ldl -lX11
                                                                                 # -framework
                                                                                 # Cocoa
                                                                                 # -framework
                                                                                 # IOKit
                                                                                 # -Werror
  )
  # You can add (-Werror), but it will make the complier more restrictive.
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

endif()
