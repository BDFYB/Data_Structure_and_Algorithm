GXX = g++
GXX_FLAGS = -Wall -lpthread

RM = rm -f
TARGET = main

.PHONY: clean, build

build: ./main.cpp
	$(GXX) $(GXX_FLAGS) ./main.cpp -o $(TARGET)

clean:
	$(RM) $(TARGET)
