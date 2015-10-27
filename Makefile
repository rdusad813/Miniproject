all: rishabh
rishabh: project.o
	cc main.c project.o -o rishabh
project.o: 
	cc -c project.c
