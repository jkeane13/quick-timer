.DEFAULT_GOAL := build

CC = gcc
APP_NAME = timer
SRC = src
TEST = tests
BIN = build

C_TESTS := $(shell find $(TEST) -name '*_test.c' -exec basename {} \; | awk -F '_test.c' {'print $$1'})

EXECUTABLE_SOURCE := $(SRC)/main.c
COMMON_SOURCES := $(filter-out $(EXECUTABLE_SOURCE),$(wildcard $(SRC)/*.c))

build:
	mkdir -p $(BIN)
	$(CC) -o $(BIN)/$(APP_NAME) $(EXECUTABLE_SOURCE) $(COMMON_SOURCES)

test:
	mkdir -p $(BIN)
	for i in $(C_TESTS); do \
	  $(CC) -o $(BIN)/$${i}_test $(TEST)/$${i}_test.c tests/testing.c $(COMMON_SOURCES); \
	  $(BIN)/$${i}_test; \
	  echo; \
	  done

deploy: build
	 mkdir -p ${HOME}/.local
	 mkdir -p ${HOME}/.local/bin
	 mkdir -p ${HOME}/.local/assets
	 cp $(BIN)/$(APP_NAME) ${HOME}/.local/bin/
	 cp -f assets/duck_quack.mp3 ${HOME}/.local/assets/

clean:
	$(RM) $(BIN)/*

.PHONY: all build
.SILENT:
