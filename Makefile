##################################################
#                                                #
#      █▀▄▀█ ▄▀█ █▄▀ █▀▀   █▀▀ █ █░░ █▀▀         #
#      █░▀░█ █▀█ █░█ ██▄   █▀░ █ █▄▄ ██▄         #
#                                                #
##################################################
# Variables
BINARY_NAME=main
NUMBER_CORES=8
SDL2_DIR = $(HOMEBREW_DIR)/sdl2/2.28.3
SDL2_IMAGE_DIR = $(HOMEBREW_DIR)/sdl2_image/2.6.3_2
SOURCES = src/main.cpp src/lib/veclib/vector2d.cpp
OUTPUT = build/debug/main
# Phony target since 'runcli' isn't a file
.PHONY: all debug release run



all: debug

debug: link_compile_commands
	cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build/debug
	$(MAKE) build/debug -j $(NUMBER_CORES)
	./build/debug/$(BINARY_NAME)

release: link_compile_commands
	cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/release
	$(MAKE) build/release -j $(NUMBER_CORES)
	./build/debug/$(BINARY_NAME)

# For the clangd language server integration
link_compile_commands:
	if [ -L compile_commands.json ]; then \
		rm -f compile_commands.json; \
	fi
	ln -s build/debug/compile_commands.json compile_commands.json

