#ifndef programa
#define programa

#define INDICE_CHAR(c) ((int)c - (int)'a')

void *mallocc (size_t nbytes);/* Função que avisa caso malloc devolva NULL */

typedef struct trie nodo;  /* Cria struct nodo */

typedef struct base raiz;   /* Raíz trie */

struct trie {         /* NODO */
  nodo *letra [27];            /* Vetor int para caracteres */
  char *palavra;             /* Qual palavra formou? */
  int filhos;
  nodo *pai;
};

struct base {        /* RAÍZ */
  nodo *primeiro ;                    /* Pointer struct trie */
};

FILE* abreDicio ();

int* maiuscMinusc(int* palavra);  /* Troca Maiúsculas -> Minúsculas */

int conferePalavra(int* palavra);  /* retorna 0 se errado, 1 se certo */

int *copiaFile(FILE *entrada, int* palavra);

nodo* criaNo();

raiz* criaTrie();            /* Cria Raíz da Trie */

int inserePalavra(nodo* N, int* palavra);

nodo *get(nodo *N, int *palavra);

int procura(nodo *N, int *palavra);

int encheTrie();

#endif
