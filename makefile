CC = g++
DEP = -lsfml-graphics -lsfml-window -lsfml-system SortWindow/SortWindow.cpp
NAME = sortvisualizer
all:
	$(CC) $(NAME).cpp $(DEP) -o $(NAME).exe