NAME = hw1
SRC = main.cpp

# No need to track deps since everything uses templates anyways; there is no benefit since everything gets recompiled
.PHONY: run fmt all 

run:
	./${NAME}

fmt:
	clang-format -i *.h *.cpp

all:
	g++ -Wall -Werror -std=c++98 -pedantic ${SRC} -o ${NAME}