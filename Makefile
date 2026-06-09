.DEFAULT_GOAL := build

CC = gcc
APP_NAME = timer
SRC = src
TEST = tests
TARGET= timer
BIN = build
WIN_EXEC = .exe

C_TESTS := $(shell find $(TEST) -name '*_test.c' -exec basename {} \; | awk -F '_test.c' {'print $$1'})

EXECUTABLE_SOURCE := $(SRC)/main.c
COMMON_SOURCES := $(filter-out $(EXECUTABLE_SOURCE),$(wildcard $(SRC)/*.c))

lint:
	./assets/clinter src/ .c
	echo
	./assets/clinter tests/ .c

build:
	mkdir -p $(BIN)
	$(CC) -o $(BIN)/$(APP_NAME) $(EXECUTABLE_SOURCE) $(COMMON_SOURCES)

run:
	./$(BIN)/$(TARGET)

release: $(SRC)
	@$(CC) $(CFLAGS) -O2 -o $(TARGET)$(RELEASE_TARGET) $(EXECUTABLE_SOURCE) $(COMMON_SOURCES)

test:
	mkdir -p $(BIN)
	for i in $(C_TESTS); do \
	  $(CC) -o $(BIN)/$${i}_test $(TEST)/$${i}_test.c tests/testing.c $(COMMON_SOURCES); \
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
