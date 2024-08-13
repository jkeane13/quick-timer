.DEFAULT_GOAL := build
.SILENT:

CC = gcc
APP_NAME = timer

build:
	$(CC) $(APP_NAME).c \
	-o $(APP_NAME)

test: build
	./$(APP_NAME)

deploy: build
	mv $(APP_NAME) ${HOME}/.local/bin/

clean:
	rm -f ./$(APP_NAME)

