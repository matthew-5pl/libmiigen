CC		:= gcc
CFLAGS	:= -Wall -g -O2 -std=c99
LFLAGS	:= -lm $(CURDIR)/libmiigen.so
SRC		:= src
CFILES	:= $(wildcard *.c)
OFILES	:= $(CFILES:.c=.o)
TARGET	:= test

all: $(TARGET)

$(TARGET): $(OFILES)
	@echo "Linking..."
	@$(CC) $(OFILES) $(LFLAGS) -o $(TARGET)

$(SRC)/%.o: $(SRC)/%.c
	@echo "Compiling object $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf src/*.o *.so *.exe

cleanall: clean
	rm -rf *.bin *.ms