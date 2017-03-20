CFLAG = -Wall -Werror
SRC = src
BIN = bin
BUILD = build
TARGET   = deposit-calc


SOURCES  := $(wildcard $(SRC)/*.c)
INCLUDES := $(wildcard $(SRC)/*.h)
OBJECTS  := $(SOURCES:$(SRC)/%.c=$(BUILD)/%.o)
rm       = rm -f

$(BIN)/$(TARGET): $(OBJECTS)
	@gcc $(CFLAGS) -o $@ $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(BUILD)/%.o : $(SRC)/%.c
	@gcc $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BIN)/$(TARGET)
	@echo "Executable removed!"

#main: main.o deposit.o
#	gcc $(CFLAG) -o $(BIN)/main $(BUILD)/main.o $(BUILD)/deposit.o
#
#main.o: $(SRC)/main.c
#	gcc $(CFLAG) -o $(BUILD)/main.o -c $(SRC)/main.c
#
#deposit.o: $(SRC)/deposit.c
#	gcc $(CFLAG) -o $(BUILD)/deposit.o -c $(SRC)/deposit.c
#
#clean: 
#	rm -f $(BUILD)/*
#	rm -f $(BIN)/*
