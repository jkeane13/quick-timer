.DEFAULT_GOAL := build

CC = gcc
APP_NAME = timer
SRC = src
TEST = tests
BIN = build

EXECUTABLE_SOURCE := $(SRC)/main.c
COMMON_SOURCES := $(filter-out $(EXECUTABLE_SOURCE),$(wildcard $(SRC)/*.c))

build:
	$(CC) -o $(BIN)/$(APP_NAME) $(EXECUTABLE_SOURCE) $(COMMON_SOURCES)

test:
	@$(CC) -o $(BIN)/args_prompt_handler_test $(TEST)/args_prompt_handler_test.c tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/args_prompt_handler_test
	@echo
	@$(CC) -o $(BIN)/args_switch_handler_test $(TEST)/args_switch_handler_test.c tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/args_switch_handler_test
	@echo
	@$(CC) -o $(BIN)/convert_12_hour_clock_to_24_test $(TEST)/convert_12_hour_clock_to_24_test.c tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/convert_12_hour_clock_to_24_test
	@echo
	@$(CC) -o $(BIN)/convert_24_clock_to_12_test $(TEST)/convert_24_clock_to_12_test.c tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/convert_24_clock_to_12_test
	@echo
	@$(CC) -o $(BIN)/convert_24_hour_clock_to_seconds_test $(TEST)/convert_24_hour_clock_to_seconds_test.c tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/convert_24_hour_clock_to_seconds_test
	@echo
	@$(CC) -o $(BIN)/convert_args_to_seconds_test $(TEST)/convert_args_to_seconds_test.c tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/convert_args_to_seconds_test
	@echo
	@$(CC) -o $(BIN)/convert_quick_clock_to_24_test $(TEST)/convert_quick_clock_to_24_test.c  tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/convert_quick_clock_to_24_test
	@echo
	@$(CC) -o $(BIN)/countdown_seconds_test $(TEST)/countdown_seconds_test.c tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/countdown_seconds_test
	@echo
	@$(CC) -o $(BIN)/get_hour_and_minutes_test $(TEST)/get_hour_and_minutes_test.c  tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/get_hour_and_minutes_test
	@echo
	@$(CC) -o $(BIN)/run_application_test $(TEST)/run_application_test.c tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/run_application_test
	@echo
	@$(CC) -o $(BIN)/usage_test $(TEST)/usage_test.c tests/testing.c $(COMMON_SOURCES)
	@$(BIN)/usage_test

test-output: build test
	@echo Testing hour...
	$(BIN)/$(APP_NAME) 12 20 2 --dry-run
	@echo Testing minute...
	$(BIN)/$(APP_NAME) 2 30  --dry-run
	@echo Testing second...
	$(BIN)/$(APP_NAME) 35 --dry-run
	@echo Testing quick clock...
	$(BIN)/$(APP_NAME) 9:30pm --dry-run
	@echo Testing application execution...
	$(BIN)/$(APP_NAME) 1 tests/example.sh

test-prompt: build
	@echo
	@echo Prompt Testing:
	$(BIN)/$(APP_NAME) -p

test-full: test test-output test-prompt

deploy: build
	 cp $(BIN)/$(APP_NAME) ${HOME}/.local/bin/
	 cp -f assets/duck_quack.mp3 ${HOME}/.local/assets/

clean:
	$(RM) $(BIN)/*

.PHONY: all build
