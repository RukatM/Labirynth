a.out: maze.o main.o
	cc main.o maze.o
main.o: maze.h
	cc -c main.c
maze.o: maze.h
	cc -c maze.c	
clean:
	rm *.o a.out
