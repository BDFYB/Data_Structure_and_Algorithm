GXX = g++
GXX_FLAGS = -Wall
INCLUDE = -I ./include

RM = rm -f
OBJ = ./src/tree.o
TARGET = main

.PHONY: clean, build

build: $(OBJ)
	$(GXX) $(GXX_FLAGS) $(INCLUDE) $(OBJ) -o $(TARGET)

$(OBJ): ./src/tree.cpp
	$(GXX) $(GXX_FLAGS) $(INCLUDE) -c ./src/tree.cpp -o $(OBJ)

clean:
	$(RM) $(TARGET) $(OBJ)
