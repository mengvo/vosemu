CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = vosume
ROM = dmg-acid2.gb

SRCS = src/main.c src/memory.c
OBJS = build/main.o build/memory.o

all: $(TARGET)

# builds executable w object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# converts .c to .o
build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	@./$(TARGET) 

rom: all
	@./$(TARGET) $(ROM)

clean:
	rm -f build/*

