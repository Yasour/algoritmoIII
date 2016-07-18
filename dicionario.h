#ifndef programa
#define programa

#define INDICE_CHAR(c) ((int)c - (int)'a')

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

/* Função que avisa caso malloc devolva NULL */
void *mallocc (size_t nbytes);

/* Cria struct nodo */
typedef struct trie nodo;

/* Raíz trie */
typedef struct base raiz;

 /* NODO */
struct trie {
  /* Vetor int para caracteres */
  nodo *letra [27];
  int filhos;
  char *palavra;
};

/* RAÍZ */
struct base {
  /* Pointer struct trie */
  nodo *primeiro ;
};

FILE* abreDicio ();

/* Troca Maiúsculas -> Minúsculas */
char* maiuscMinusc(char* palavra);

/* retorna 0 se errado, 1 se certo */
int conferePalavra(char* palavra);

nodo* criaNo(nodo *p);

/* Cria Raíz da Trie */
raiz* criaTrie();
/* Recebe vetor com palavra conferida */
int inserePalavra(nodo* N, char* palavra);

nodo *encheTrie();

int levenshtein(char *s1, char *s2);

int confereLeven(nodo *no, char *pal, int leven);

int procura(FILE *saida, nodo *n, char *pal, int leven, int cont);

#endif
