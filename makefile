CFLAG = -Wall -Werror
SRC = src
SRCTEST = test
BIN = bin
BUILD = build/src
BUILDTEST = build/test
TARGET   = deposit-calc
SIMPlEUTEST = simple-utest
CC = gcc
TESTCOMPILE = -I thirdparty -I $(SRC)


SOURCES  := $(wildcard $(SRC)/*.c)
SOURCESTEST  := $(wildcard $(SRCTEST)/*.c)
INCLUDES := $(wildcard $(SRC)/*.h)
OBJECTS  := $(SOURCES:$(SRC)/%.c=$(BUILD)/%.o)
OBJECTSTEST  := $(SOURCESTEST:$(SRCTEST)/%.c=$(BUILDTEST)/%.o)
rm       = rm -f


$(BIN)/$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(BUILD)/%.o : $(SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

simple-test: $(BIN)/$(SIMPlEUTEST)
	@echo "Compiled simple-test "$<" successfully!"

$(BIN)/$(SIMPlEUTEST): $(BUILDTEST)/main.o
	$(CC) $(TESTCOMPILE) $(CFLAGS) $(BUILDTEST)/main.o -o $@

$(OBJECTSTEST): $(BUILDTEST)/%.o : $(SRCTEST)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled test "$<" successfully!"

.PHONY: clean
clean:
	$(rm) $(OBJECTS)
	$(rm) $(OBJECTSTEST)
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
