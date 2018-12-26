.PHONY: all clean

OBJ=obj
BIN=bin
EXE="heap"

all: $(OBJ)/main.o $(OBJ)/heap.o

	mkdir -p bin
	mkdir -p obj
	gcc -o $(BIN)/$(EXE) $(OBJ)/main.o $(OBJ)/heap.o
	
clean:
	mkdir -p bin
	mkdir -p obj
	rm $(BIN)/*
	rm $(OBJ)/*
	
$(OBJ)/main.o: main.c heap.h
	mkdir -p obj
	gcc -c -o $(OBJ)/main.o main.c

$(OBJ)/heap.o: heap.c heap.h
	mkdir -p obj
	gcc -c -o $(OBJ)/heap.o heap.c
		
