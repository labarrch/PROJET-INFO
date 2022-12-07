CFLAGS=-g -Wall

all: parser

parser : parser.o output.o input.o blocs.o and2.o or2.o
	g++ -o parser $^ $(LDFLAGS)

%.o:%.cpp
	g++ $(CFLAGS) -c -g $^
