CC = g++
CFLAGS = -Wall -std=c++11
OBJS = main.o memoryKrea.o
EXE = admission_makefile

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

main.o: main.cpp memoryKrea.h
	$(CC) $(CFLAGS) -c main.cpp

memoryKrea.o: memoryKrea.cpp memoryKrea.h
	$(CC) $(CFLAGS) -c memoryKrea.cpp

clean:
	rm -f $(OBJS) $(EXE)

