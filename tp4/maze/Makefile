CC=g++
CFLAGS=-W -Wall -O3
LDFLAGS=
EXEC=maze
S1SRC= main.cpp grille.cpp vector2D.cpp
S1OBJ= $(S1SRC:.cpp=.o)

all: $(EXEC)

maze: $(S1OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
