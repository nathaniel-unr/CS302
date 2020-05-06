CC = g++
NAME = hw6
SRC = main.cpp
CPP_FLAGS = -Wall -Werror -std=c++11 -pedantic

.PHONY: run fmt all 

all:
	${CC} ${CPP_FLAGS} ${SRC} -o ${NAME}
	
run:
	./${NAME}

fmt:
	clang-format -i *.cpp