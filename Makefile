CC=g++
CFLAGS=-g -Wall
all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))
%.out: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.out *~ core *.dSYM/
