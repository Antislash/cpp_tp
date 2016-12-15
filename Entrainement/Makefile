CC=g++
CFLAGS=-W -Wall -O3
LDFLAGS=
EXEC= game
S1SRC= game.cpp file.cpp question.cpp
S1OBJ= $(S1SRC:.cpp=.o)

all: $(EXEC)

game: $(S1OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
