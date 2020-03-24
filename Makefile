CC = gcc

OBJS = ./src/main.cpp ./src/simulation.cpp ./src/population.cpp ./src/individual.cpp ./src/arguments.cpp
INCS = -Iinclude
COMPILER_FLAGS = -lm

OBJ_NAME = main

all : $(OBJS)
	$(CC) $(OBJS) $(INCS) $(COMPILER_FLAGS) -o $(OBJ_NAME)

clean :
	rm $(OBJ_NAME) *.csv
 
 .PHONY: clean