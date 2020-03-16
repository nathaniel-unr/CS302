NAME = hw2
SRC = postfix.cpp

.PHONY: run fmt all 

run:
	./${NAME}

fmt:
	clang-format -i *.h *.cpp

all:
	g++ -Wall -Werror -std=c++98 -pedantic ${SRC} -o ${NAME}