CFLAGS=-g -Wall

all: parser


parser : parser.o
	g++ -o parser $^ $(LDFLAGS)
	rm *.o
	rm *.gch

tester : testeur_2.o
	g++ -o parser $^ $(LDFLAGS)
	rm *.o
	rm *.gch

%.o:%.cpp
	g++ $(CFLAGS) -c -g $^


clean :
	rm -f $(EXEC_NAME) $(OBJ_FILES)
