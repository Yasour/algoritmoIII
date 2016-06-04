all:	programa
programa:		dicionario.o	main.o
							gcc	-o	programa	dicionario.o	main.o
dicionario.o:	dicionario.c
							gcc	-o	dicionario.o	-c	dicionario.c	-W	-Wall	-ansi	-pedantic
main.o:			main.c	dicionario.h
							gcc	-o	main.o	-c	main.c	-W	-Wall	-ansi	-pedantic
clean:
							rm	-rf	*.o
