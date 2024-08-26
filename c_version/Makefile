.DEFAULT_GOAL := build

CC = gcc
APP_NAME = timer
TEST_APP_NAME = $(APP_NAME)_test
SRC=src
TEST=tests
BIN=build

EXECUTABLE_SOURCE := $(SRC)/main.c
TESTSUITE_SOURCE := $(TEST)/timer_test.c

COMMON_SOURCES := $(filter-out $(TESTSUITE_SOURCE) $(EXECUTABLE_SOURCE),$(wildcard $(SRC)/*.c))

build:
	$(CC) -o $(BIN)/$(APP_NAME) $(EXECUTABLE_SOURCE) $(COMMON_SOURCES)

test:
	@echo Function Testing:
	$(CC) -o $(BIN)/$(TEST_APP_NAME) $(TESTSUITE_SOURCE) $(COMMON_SOURCES)
	@$(BIN)/$(TEST_APP_NAME)

test-dry: build test
	@echo
	@echo Output Testing:
	$(BIN)/$(APP_NAME) 1 2 3 --dry-run

test-prompt: build test
	@echo
	@echo Prompt Testing:
	$(BIN)/$(APP_NAME) -p

test-full: test test-dry test-prompt

deploy: build
	 cp $(BIN)/$(APP_NAME) ${HOME}/.local/bin/
	 cp -f assets/duck_quack.mp3 ${HOME}/.local/assets/

clean:
	$(RM) $(BIN)/*

.PHONY: all build
