a.out: main.o board.o
	gcc main.o board.o

main.o: main.c board.h
	gcc -c main.c board.h

board.o: board.c
	gcc -c board.c
