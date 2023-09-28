# Phony target since 'runcli' isn't a file
.PHONY: all debug release run


all: debug

debug:
	cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build/debug && cd build/debug && make && ./main
	cd ../../
	rm compile_commands.json && ln -s build/debug/compile_commands.json compile_commands.json

release:
	cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/release && cd build/release && make && ./main
	cd ../../
	rm compile_commands.json && ln -s build/release/compile_commands.json compile_commands.json

