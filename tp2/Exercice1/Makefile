CC=g++
CFLAGS=-W -Wall -O3
LDFLAGS=
EXEC=complex
S1SRC= main.cpp 
S1OBJ= $(S1SRC:.cpp=.o)

all: $(EXEC)

complex: $(S1OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
