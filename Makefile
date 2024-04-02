CC = g++ -o build/

all: compile

compile:
	mkdir -p build
	$(CC)/main src/main.cpp
	./build/main
