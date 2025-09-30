#1 Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

#2 Target executable
TARGET = MyBitApp

#3 Source files
CFILES = main.c bits.c mylist.c

#4 Object files
OBJECTS = $(CFILES:.c=.o)

#5 Header files
HEADERS = bits.h mylist.h

#5 Default rule - building executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

#6 Rule for main.o - depends on main.c and both header files
main.o: main.c bits.h mylist.h
	$(CC) $(CFLAGS) -c main.c

#7 Rule for bits.o - depends on bits.c and bits.h
bits.o: bits.c bits.h
	$(CC) $(CFLAGS) -c bits.c

#8 Rule for mylist.o - depends on mylist.c and mylist.h
mylist.o: mylist.c mylist.h
	$(CC) $(CFLAGS) -c mylist.c

all:
	@echo "Building project..."

#9 Clean rule - removes object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean