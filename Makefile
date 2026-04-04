#Author: Gabrielle Dement
#File: Makefile for Game library program
#Date Created: 04/04/2026
#Last Modified: 04/04/2026
#Purpose: Builds the game library management system

CC = g++

TARGET = game-lib

CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): main.o Library.o
	$(CC) -g main.o Library.o -o $(TARGET)

main.o: main.cpp Library.h Game.h
	$(CC) $(CFLAGS) main.cpp

Library.o: Library.cpp Library.h Game.h
	$(CC) $(CFLAGS) Library.cpp

clean:
	$(RM) $(TARGET) *.o *~

