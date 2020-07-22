MAIN = src/main.cpp
GAME = src/game.cpp 
GRAPHICS = src/graphics.cpp 
INPUT = src/input.cpp 
SPRITE = src/sprite.cpp
CC = g++
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2 -lSDL2_image
OBJ_NAME = game
all : $(MAIN) 
	$(CC) $(MAIN) $(GAME) $(GRAPHICS)  $(INPUT) $(SPRITE) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
