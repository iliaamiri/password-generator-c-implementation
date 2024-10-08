
out: main.o lib.o
	gcc main.o lib.o -o passgen

debug: main.o lib.o
	gcc -g -o -O0 passgen main.o lib.o

main.o: main.c
	gcc -c main.c -o main.o

lib.o: lib.c lib.h
	gcc -c lib.c -o lib.o

clear:
	rm *.o
