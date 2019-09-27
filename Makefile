IDIR =./include
SRC =./src/
CC=g++

all:
	${CC} -o binTree ${SRC}* -I ${IDIR}
