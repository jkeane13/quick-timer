.DEFAULT_GOAL := build

CC = gcc
APP_NAME = timer
TEST_APP_NAME = $(APP_NAME)_test
SRC=src
TEST=tests
BIN=build

SRCS := $(wildcard $(SRC)/*.c)
SRCS_TEST := $(wildcard $(TEST)/*.c)

build:
	@$(CC) -o $(BIN)/$(APP_NAME) $(SRCS)

test:
	@echo Function Testing:
	$(CC) -o $(BIN)/$(TEST_APP_NAME) $(SRC)/$(APP_NAME).c $(SRCS_TEST)
	@$(BIN)/$(TEST_APP_NAME)

test-full: build test
	@echo
	@echo Output Testing:
	$(BIN)/$(APP_NAME) 1 2 3 --dry-run

deploy: build
	 cp $(BIN)/$(APP_NAME) ${HOME}/.local/bin/
	 cp -f assets/duck_quack.mp3 ${HOME}/.local/assets/

clean:
	$(RM) $(BIN)/*

.PHONY: all build
