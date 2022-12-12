CFLAGS=-g -Wall

all: parser

parser : parser.o
	g++ -o parser $^ $(LDFLAGS)

%.o:%.cpp
	g++ $(CFLAGS) -c -g $^

clean :
	rm -f *.o
	rm -f parser
