.DEFAULT_GOAL := build
.SILENT:

CC = gcc
APP_NAME = timer

build:
	$(CC) main.c $(APP_NAME).c \
	-o $(APP_NAME)

test: build
	echo Function Testing:
	$(CC) $(APP_NAME)_test.c $(APP_NAME).c -o ./$(APP_NAME)_test
	./$(APP_NAME)_test
	echo
	echo Output Testing:
	./$(APP_NAME) 3 --dry-run

deploy: build
	mv $(APP_NAME) ${HOME}/.local/bin/

clean:
	rm -f ./$(APP_NAME)
	rm -f ./$(APP_NAME)_test
