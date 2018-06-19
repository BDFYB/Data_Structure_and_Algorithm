GXX = g++
GXX_FLAGS = -Wall
INCLUDE = -I ./include

RM = rm -f
OBJ = ./src/tree.o
OBJ += ./src/main.o
OBJ += ./src/solution.o
TARGET = main

.PHONY: clean, build

build: $(OBJ)
	$(GXX) $(GXX_FLAGS) $(INCLUDE) $(OBJ) -o $(TARGET)

./src/%.o: ./src/%.cpp
	$(GXX) $(GXX_FLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJ)
