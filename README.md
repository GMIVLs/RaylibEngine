# RAYLIB ENGINE

## ChangingLog

- `2023-09-29`: building the structure dependencies
  - Added the basic structure of my current animation engine in `raylib` library.
  - Used the `vcpkg` package maanger to install the dependencies for current project.
  - Created a documentation on how to use the `vcpkg` in this project.
  - `CMakeList.txt`, `Makefile` both have been updated with automation features.

## Requirement

### Options for using Raylib

1. You can refer to the build using the AppKit or IOKit for building the `raylib` by adding the following to your CMakeList.txt file ,

```sh
find_library(APPKIT_LIBRARY AppKit)
find_library(IOKIT_LIBRARY IOKit)
```

and the build command is

```cmake
# Set C++ standard (optional)
 set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_CXX_FLAGS_DEBUG
     "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g -lGL -lm -lpthread -ldl -lX11"
 )
```

2. or you can use the second option. In that case you don't need to use `find_library` anymore and only pass the commands.

```cmake
# Set C++ standard (optional)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g -lGL -lm -lpthread -ldl -lX11 -lglfw3 -framework Cocoa -framework IOKit -framework CoreFoundation " # -lrt
)
```
