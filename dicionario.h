#ifndef programa
#define programa

void *mallocc (size_t nbytes);/* Função que avisa caso malloc devolva NULL */

typedef struct trie nodo;  /* Cria struct nodo */

typedef struct base raiz;   /* Raíz trie */

struct trie {
  int letra [27];            /* Vetor int para caracteres */
  char *palavra;             /* Qual palavra formou? */
};

struct base {
  nodo *primeiro ;                    /* Pointer struct trie */
};

FILE* abreDicio ();

int* maiuscMinusc(int* entrada);  /* Troca Maiúsculas -> Minúsculas */

int conferePalavra(int* palavra);  /* retorna 0 se errado, 1 se certo */

int *copiaFile(FILE *entrada, int* palavra);

raiz* criaTrie();            /* Cria Raíz da Trie */

raiz* criaNodo(raiz *root);           /* somente cria */

raiz* inserePalavra(raiz* root, int* palavra);

#endif
