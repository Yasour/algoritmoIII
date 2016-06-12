#ifndef programa
#define programa

#define INDICE_CHAR(c) ((int)c - (int)'a')

void *mallocc (size_t nbytes);/* Função que avisa caso malloc devolva NULL */

typedef struct trie nodo;  /* Cria struct nodo */

typedef struct base raiz;   /* Raíz trie */

struct trie {         /* NODO */
  nodo *letra [27];            /* Vetor int para caracteres */
  int filhos;
  nodo *pai;
  char *palavra;
};

struct base {        /* RAÍZ */
  nodo *primeiro ;                    /* Pointer struct trie */
};

FILE* abreDicio ();

char* maiuscMinusc(char* palavra);  /* Troca Maiúsculas -> Minúsculas */

int conferePalavra(char* palavra);  /* retorna 0 se errado, 1 se certo */

char *copiaFile(FILE *entrada, char* palavra);

nodo* criaNo();

raiz* criaTrie();            /* Cria Raíz da Trie */

int inserePalavra(nodo* N, char* palavra);

nodo *get(nodo *N, char *palavra);

int procura(nodo *N, char *palavra);

nodo *encheTrie();

int levenshtein(char *s, int ls, char *t, int lt);

#endif
