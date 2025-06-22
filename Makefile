CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
TARGET = vosume
ROM = cpu_instrs.gb

SRCS = src/main.c src/memory.c src/cpu.c src/instructions.c
OBJS = build/main.o build/memory.o build/cpu.o build/instructions.o

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

