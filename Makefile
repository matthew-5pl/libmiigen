CC		:= gcc
CFLAGS	:= -Wall -g -O2
LFLAGS	:= -lm
SRC		:= src
CFILES	:= $(wildcard $(SRC)/*.c)
OFILES	:= $(CFILES:.c=.o)
TARGET	:= libmiigen.so

all: $(TARGET)

$(TARGET): $(OFILES)
	@echo "Linking..."
	@$(CC) -shared $(OFILES) $(LFLAGS) -o $(TARGET)

$(SRC)/%.o: $(SRC)/%.c
	@echo "Compiling object $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf src/*.o *.so *.exe