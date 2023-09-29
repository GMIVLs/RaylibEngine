# Options for install Raylib

1. You can refer to the build using the AppKit or IOKit for building the
   `raylib` by adding the following to your CMakeList.txt file ,

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

2. or you can use the second option. In that case you don't need to use
   `find_library` anymore and only pass the commands.

```cmake
# Set C++ standard (optional)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g -lGL -lm -lpthread -ldl -lX11 -lglfw3 -framework Cocoa -framework IOKit -framework CoreFoundation " # -lrt
)
# you will not need this
# ${COREFOUNDATION_LIBRARY}
# ${COREGRAPHICS_LIBRARY}
# ${APPKIT_LIBRARY} ${IOKIT_LIBRARY} ) # notice raylib has to be at the end,
```

## References

- [Raylib official website](https://www.raylib.com/index.html)
