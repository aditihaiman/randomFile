all: randFile.o
	gcc -o program randFile.o

randFile.o: randFile.c
	gcc -c randFile.c

run:
	./program