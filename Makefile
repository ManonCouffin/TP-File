test: element.c element.h mafile.c mafile.h application.c
	gcc -c element.c
	gcc -c mafile.c
	gcc -c application.c
	gcc -o test.out element.o mafile.o application.o
	./test.out