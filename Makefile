SHELL := /bin/bash
.DEFAULT_GOAL := build
.PHONY: build test deploy debug run-debug clean install lint
.SILENT:

# Parallel Configuration to speed up testing
OS := $(shell uname)
ifeq ($(OS),Darwin)
  JOBS ?= $(shell sysctl -n hw.ncpu)
else
  JOBS ?= $(shell nproc)
endif
MAKEFLAGS += -j$(JOBS)
CC = ccache gcc

CFLAGS = -Werror -Wall -Wextra -std=c99 -D_DEFAULT_SOURCE
RELEASE_FLAG = -O2
FAST_FLAG = -O0
DEBUG_FLAG = -g
LINK_FLAG = $(LDLIBS)

PROGRAM_NAME = timer
SOURCE_DIR = src
TEMP_DIR = $(HOME)/temp
BUILD_DIR = $(HOME)/temp/build
APP = ${TEMP_DIR}/${PROGRAM_NAME}
DEPLOY_DIR = $(HOME)/.local/bin/
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:$(SOURCE_DIR)/%.c=$(BUILD_DIR)/%.o)

TEST_DIR = tests
TEST_SOURCES = $(wildcard $(TEST_DIR)/*_test.c)
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%_test.c=$(BUILD_DIR)/test_%.o)
TEST_APPS = $(TEST_SOURCES:$(TEST_DIR)/%_test.c=$(TEMP_DIR)/test_%)

HEADERS = $(wildcard include/*.h)

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

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(HEADERS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

lint:
	@./assets/clinter src/ .c
	@echo
	@./assets/clinter tests/ .c

build: $(OBJECTS)
	$(CC) $^ $(FAST_FLAG) $(LINK_FLAG) -o $(APP)

build-optimised: $(OBJECTS)
	$(CC) $^ $(RELEASE_FLAG) $(LINK_FLAG) -o $(APP)

test: $(TEST_APPS)
	@for test_app in $(TEST_APPS); do \
	  $$test_app || exit 1; \
	done

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%_test.c $(HEADERS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEMP_DIR)/test_%: $(BUILD_DIR)/test_%.o $(filter-out $(BUILD_DIR)/main.o,$(OBJECTS))
	@mkdir -p $(TEMP_DIR)
	$(CC) $^ $(FAST_FLAG) $(LINK_FLAG) -o $@

deploy: build-optimised
	mkdir -p $(HOME)/.local/assets
	mkdir -p $(HOME)/.local/config
	mkdir -p $(DEPLOY_DIR)
	cp -f assets/*.mp3 $(HOME)/.local/assets/
	cp -f config/*.cfg $(HOME)/.local/config/
	mv $(APP) $(DEPLOY_DIR)$(PROGRAM_NAME)

run: test build
	$(APP)

debug: $(OBJECTS)
	$(CC) $^ $(CFLAGS) $(DEBUG_FLAG) $(LINK_FLAG) -o $(APP)

run-debug: debug
ifeq ($(OS),Darwin)
	lldb $(APP)
else
	gdb $(APP)
endif

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(APP)

install:
	@mkdir -p $(DEPLOY_DIR)
	@cp $(APP) $(DEPLOY_DIR)$(PROGRAM_NAME)
