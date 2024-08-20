.DEFAULT_GOAL := build

CC = gcc
APP_NAME = timer

build:
	@$(CC) main.c $(APP_NAME).c \
	-o $(APP_NAME)

test: build
	@echo Function Testing:
	@$(CC) $(APP_NAME)_test.c $(APP_NAME).c -o ./$(APP_NAME)_test
	@./$(APP_NAME)_test
	@echo
	@echo Output Testing:
	./$(APP_NAME) 1 2 3 --dry-run
	./$(APP_NAME) 4:30am --dry-run
	./$(APP_NAME) 5:30pm --dry-run

deploy: build
	mv $(APP_NAME) ${HOME}/.local/bin/

clean:
	rm -f ./$(APP_NAME)
	rm -f ./$(APP_NAME)_test
