CC := g++
CFLAGS := -Wall

SRCFILES := $(wildcard src/*.cpp)

all: $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/saida -std=c++11 -lncurses

obj/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc -std=c++11 -lncurses

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	bin/saida
