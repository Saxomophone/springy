CC = g++ -o build/

all: compile run

compile:
	mkdir -p build
	$(CC)/main src/main.cpp

run:
	./build/main
