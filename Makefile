all:	programa
programa:		funcoes.o	main.o
							gcc	-o	programa	funcoes.o	main.o
funcoes.o:	funcoes.c
							gcc	-o	funcoes.o	-c	funcoes.c	-W	-Wall	-ansi	-pedantic
main.o:			main.c	cabeca.h
							gcc	-o	main.o	-c	main.c	-W	-Wall	-ansi	-pedantic
clean:
							rm	-rf	*.o
