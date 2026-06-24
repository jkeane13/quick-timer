.DEFAULT_GOAL := build

CC = gcc
APP_NAME = timer
SRC = src
TEST = tests
TARGET= timer
BIN = build
WIN_EXEC = .exe

C_TESTS := $(shell find $(TEST) -name '*_test.c' -exec basename {} \; | awk -F '_test.c' {'print $$1'})

CFLAGS = -std=c99 -Wall -Wextra -D_DEFAULT_SOURCE

ifeq ($(OS),Windows_NT)
    LDLIBS = -lpdcurses
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        LDLIBS = -lncurses
    else
        LDLIBS = -lncursesw
    endif
endif

EXECUTABLE_SOURCE := $(SRC)/main.c
COMMON_SOURCES := $(filter-out $(EXECUTABLE_SOURCE),$(wildcard $(SRC)/*.c))

lint:
	./assets/clinter src/ .c
	echo
	./assets/clinter tests/ .c

build:
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/$(APP_NAME) $(EXECUTABLE_SOURCE) $(COMMON_SOURCES) $(LDLIBS)

run:
	./$(BIN)/$(TARGET)

release: $(SRC)
	@$(CC) $(CFLAGS) -O2 -o $(TARGET)$(RELEASE_TARGET) $(EXECUTABLE_SOURCE) $(COMMON_SOURCES) $(LDLIBS)

test:
	mkdir -p $(BIN)
	for i in $(C_TESTS); do \
	  $(CC) $(CFLAGS) -o $(BIN)/$${i}_test $(TEST)/$${i}_test.c $(COMMON_SOURCES) $(LDLIBS); \
	  $(BIN)/$${i}_test; \
	  echo; \
	  done

linux-release: RELEASE_TARGET=
linux-release: release

windows-release: RELEASE_TARGET=$(WIN_EXEC)
windows-release: release


deploy: build
	 mkdir -p ${HOME}/.local
	 mkdir -p ${HOME}/.local/bin
	 mkdir -p ${HOME}/.local/assets
	 mkdir -p ${HOME}/.local/config
	 cp -f $(BIN)/$(APP_NAME) ${HOME}/.local/bin/
	 cp -f assets/*.mp3 ${HOME}/.local/assets/
	 cp -f config/*.cfg ${HOME}/.local/config/

clean:
	$(RM) $(BIN)/*

.PHONY: build run clean test release linux-release windows-release deploy lint
