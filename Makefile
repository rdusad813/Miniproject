project: main.o project.o datastructure.o datastructure1.o datastructure2.o 
	cc main.o project.o datastructure.o datastructure1.o datastructure2.o -Wall -o project
project.o: project.c miniproject.h
	cc -c project.c
datastructure.o: datastructure.c miniproject.h
	cc -c datastructure.c
datastructure1.o: datastructure1.c miniproject.h
	cc -c datastructure1.c
datastructure2.o: datastructure2.c miniproject.h
	cc -c datastructure2.c
clean: 
	rm -f *.o project	
