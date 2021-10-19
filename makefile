all: main.o cookies.o
	gcc -o program main.o cookies.o

main.o: main.c cookies.h
	gcc -c main.c

cookies.o: cookies.c cookies.h
	gcc -c cookies.c

run:
	./program

clean:
	rm *.o
