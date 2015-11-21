all: triangulation

triangulation: main.o
	gcc -std=c11 main.o -o triangulation -Ihul/ -Lhul/ -lhul
main.o: main.c
	gcc -std=c11 -c main.c 

clean:
	rm *o
