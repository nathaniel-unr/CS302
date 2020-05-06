CC = g++
NAME = hw4
SRC = main.cpp Event.cpp Customer.cpp
CPP_FLAGS = -Wall -Werror -std=c++11 -pedantic

.PHONY: run fmt all 

run:
	./${NAME}

fmt:
	clang-format -i *.h *.cpp

all:
	${CC} ${CPP_FLAGS} ${SRC} -o ${NAME}