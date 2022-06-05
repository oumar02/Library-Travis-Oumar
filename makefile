all: library


AllAction.o: AllAction.c AllAction.h 
	gcc -c AllAction.c -o AllAction.o 

IntMain.o: IntMain.c AllAction.h 
	gcc -c IntMain.c -o IntMain.o

library: IntMain.o AllAction.o  
	gcc IntMain.o AllAction.o -o library
