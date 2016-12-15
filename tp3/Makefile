CC=g++
CFLAGS=-W -Wall -O3 --std=c++11
LDFLAGS=
EXEC=rectangle
S1SRC= main.cpp rectangle.cpp square.cpp
S1OBJ= $(S1SRC:.cpp=.o)

all: $(EXEC)

rectangle: $(S1OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)