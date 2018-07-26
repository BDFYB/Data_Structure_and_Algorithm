GXX = g++
GXX_FLAGS = -Wall
INCLUDE = -I ./include 
OBJ = ./src/main.o
OBJ += ./src/tree.o
TARGET = main
RM = rm -f 

.PHONY: clean, build

$(TARGET): $(OBJ)
	$(GXX) $(GXX_FLAGS) $(INCLUDE) $(OBJ) -o $(TARGET)

./src/%.o: ./src/%.cpp
	$(GXX) $(GXX_FLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ) $(TARGET)
