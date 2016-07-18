all:	dicionario
dicionario:		dicionario.o	main.o
							gcc	-o	dicionario	dicionario.o	main.o
dicionario.o:	dicionario.c
							gcc	-o	dicionario.o	-c	dicionario.c
main.o:			main.c	dicionario.h
							gcc	-o	main.o	-c	main.c
clean:
							rm	-rf	*.o
