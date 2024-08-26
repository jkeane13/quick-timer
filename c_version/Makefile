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

test-dry-time-hour: build test
	@echo
	$(BIN)/$(APP_NAME) 12 20 2 --dry-run

test-dry-time-minute: build
	@echo
	$(BIN)/$(APP_NAME) 2 30  --dry-run

test-dry-time-second: build
	@echo
	$(BIN)/$(APP_NAME) 35 --dry-run

test-dry-clock: build
	@echo
	$(BIN)/$(APP_NAME) 9:30pm --dry-run

test-program: build
	@echo Program Testing...
	$(BIN)/$(APP_NAME) 1 tests/example.sh

test-prompt: build
	@echo
	@echo Prompt Testing:
	$(BIN)/$(APP_NAME) -p

test-all: test test-dry-time-hour test-dry-time-minute test-dry-time-second test-dry-clock test-program test-prompt

deploy: build
	 cp $(BIN)/$(APP_NAME) ${HOME}/.local/bin/
	 cp -f assets/duck_quack.mp3 ${HOME}/.local/assets/

clean:
	$(RM) $(BIN)/*

.PHONY: all build
