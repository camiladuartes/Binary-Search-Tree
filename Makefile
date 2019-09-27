IDIR =./include
SRC =./src/
CC=g++
FLAGS=-std=c++11

all:
	${CC} -o binTree ${SRC}* -I ${IDIR} ${FLAGS}
