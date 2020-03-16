CC = g++
NAME = hw3
SRC = main.cpp
CPP_FLAGS = -Wall -Werror -std=c++11 -pedantic
TURBO_FLAGS = -Ofast -DNDEBUG -march=native -mtune=native -flto #Stable? Who needs Stable?

.PHONY: run fmt all 

run:
	./${NAME}

fmt:
	clang-format -i *.h *.cpp

all:
ifndef TURBO
	${CC} ${CPP_FLAGS} ${SRC} -o ${NAME}
else
	${CC} ${CPP_FLAGS} ${TURBO_FLAGS} ${SRC} -o ${NAME}
endif
