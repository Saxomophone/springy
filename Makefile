CC = g++ -o build/

all: compile run

compile:
	mkdir -p build
	mkdir -p generated
	$(CC)/main src/main.cpp

run:
	./build/main
	python3 src/plot.py

plot:
	python3 src/plot.py