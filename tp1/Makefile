CC=g++
CFLAGS=-W -Wall -O3
LDFLAGS=
EXEC=step1 step2
S1SRC= step1.cpp file.cpp
S1OBJ= $(S1SRC:.cpp=.o)
S2SRC= step2.cpp file.cpp point.cpp
S2OBJ= $(S2SRC:.cpp=.o)

all: $(EXEC)

step1: $(S1OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

step2: $(S2OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
