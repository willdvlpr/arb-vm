SRC_FILES = src/vm.c
CC_FLAGS = -Wall -Wextra -g -std=c11
CC = clang

all:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o arb_vm
