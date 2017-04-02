#compile
CC = gcc
CFLAG = -Wall -Werror
TESTFLAG = -I thirdparty -I $(SRC) $(CFLAG)
#folder define
SRC = src
SRCTEST = test
BIN = bin
BUILD = build/src
BUILDTEST = build/test
DIRGUARD=@mkdir -p $(@D)
#target
TARGET   = deposit-calc
SIMPlEUTEST = simple-utest
VALIDUTEST = validation_test
DEPOSITTEST = deposit_test
#sources
SOURCES  := $(wildcard $(SRC)/*.c)
SOURCESTEST  := $(wildcard $(SRCTEST)/*.c)
#INCLUDES := $(wildcard $(SRC)/*.h)
#objects
OBJECTS  := $(SOURCES:$(SRC)/%.c=$(BUILD)/%.o)
OBJECTSTEST  := $(SOURCESTEST:$(SRCTEST)/%.c=$(BUILDTEST)/%.o)

rm       = rm -f

#deposit-calc
$(BIN)/$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	@echo "Linking complete!"

#deposit-calc objects
$(OBJECTS): $(BUILD)/%.o : $(SRC)/%.c
	@$(DIRGUARD)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

#test objects
$(OBJECTSTEST): $(BUILDTEST)/%.o : $(SRCTEST)/%.c
	@$(DIRGUARD)
	@$(CC) $(TESTFLAG) $(CFLAGS) -c $< -o $@
	@echo "Compiled test "$<" successfully!"

.PHONY: test
test:$(OBJECTSTEST) $(OBJECTS)
	@$(CC) $(TESTFLAG) $(BUILDTEST)/main.o -o $(BIN)/$(SIMPlEUTEST)
	@$(CC) $(TESTFLAG) $(BUILD)/deposit.o $(BUILDTEST)/validation_test.o -o $(BIN)/$(VALIDUTEST)
	@$(CC) $(TESTFLAG) $(BUILD)/deposit.o $(BUILDTEST)/deposit_test.o -o $(BIN)/$(DEPOSITTEST)

.PHONY: run_test
run_test:test
	./$(BIN)/$(VALIDUTEST)
	./$(BIN)/$(DEPOSITTEST)

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rm) $(OBJECTSTEST)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BIN)/*
	@echo "Executable removed!"