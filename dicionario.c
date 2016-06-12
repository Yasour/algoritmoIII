#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicionario.h"

void *mallocc (size_t nbytes){          /* Função que avisa caso malloc devolva NULL */
  void *ptr;
  ptr = malloc (nbytes);
  if (ptr == NULL) {
    printf ("Socorro! malloc devolveu NULL!\n");
    exit (EXIT_FAILURE);
  }
  return ptr;
}

FILE* abreDicio (){                     /* Abre FILE do Dicionario corretamente */
  FILE *entrada;
  entrada = fopen ("dicionario.txt", "r");
  if (entrada == NULL) {
      printf("\nNão encontrei o arquivo dicionario.txt.\n");
      exit (EXIT_FAILURE);
  }
  return entrada;
}

char* maiuscMinusc(char* palavra){       /* Troca Maiúsculas -> Minúsculas */
  int i;
  for (i = 0; palavra [i] != 10; i++){

    if (palavra [i] >=65 && palavra [i] <= 90 ){
      palavra [i] += 32 ;
    }
  }
  return palavra;
}

int conferePalavra(char* palavra){
  int i, flag;
  palavra = maiuscMinusc (palavra);

  flag = 1;
  for (i = 0; palavra[i] != 10 ; i++){
    if (palavra [i] < 97 || palavra [i] > 123){  /* Caso seja diferente de letras minusculas e pula linha */
      flag = 0;
    }
  }

  if (flag == 1){
    return 1; /* CERTO */
  } else {
    return 0; /* ERRADO */
  }

}

char *copiaFile(FILE *entrada, char* palavra){         /* .txt -> vetor */

  int i, j;
  i = 0;

  while (i < 30){
    palavra [i] = fgetc (entrada);  /* copie do .txt 1 char */

    if (palavra [i] == EOF){
      palavra[0] = 10;
      return palavra;
    }
    if (palavra [i] == 10) {         /* fim FILE ou fim palavra */

      j = conferePalavra(palavra);
      if (j == 0){
        i = 0;
        palavra [i] = fgetc (entrada);
        j = conferePalavra(palavra);
      }else
      if (j == 1){
        return palavra;         /* Aqui fará com que saia do laço WHILE */
      }
    }
    i++;
  }
  return palavra;                     /* Vetor com o trecho */
}

nodo* criaNo(){           /* somente cria */
  int i ;
  nodo* no;

  no = mallocc (sizeof(nodo));

  for (i = 0; i < 27; i++){
    no -> letra [i] = NULL ;             /* valor inicial do vetor 0 */
  }

  no -> filhos = 0;
  no -> pai = NULL;
  no -> palavra = NULL;

  return no;                        /* retornará o endereço raiz */
}

raiz *criaTrie(){                     /* Função cria Raíz Trie */
  raiz *root;
  nodo* no;
  root = mallocc (sizeof(raiz));
  no = criaNo();
  root -> primeiro = no;

  return root;
}


int inserePalavra(nodo* N, char* palav){    /* Recebe vetor com palavra conferida */
  int i, pos;
  nodo *auxNodo;
  nodo *novoNodo;

  auxNodo = N;                  /* vou inserir o primeiro nodo indicado pela RAIZ */

  for (i = 0; palav[i] != 10; i++){
    pos = INDICE_CHAR (palav [i]);    /* posição 00~26*/

    if (auxNodo -> letra [pos]){        /* se existir */
      auxNodo = auxNodo -> letra [pos];
    } else {
      novoNodo = criaNo();
      auxNodo -> letra [pos] = novoNodo;
      novoNodo -> pai = auxNodo;
      auxNodo -> filhos++;        /* agora tem 1 filho */
      auxNodo = novoNodo;
    }
  }

  auxNodo -> palavra = mallocc (30 * (sizeof(char)));

  for (i = 0; palav[i] != 10; i++){     /* copia o char da palavra completa no último nodo */
    auxNodo -> palavra[i] = palav[i];
  }
    auxNodo -> palavra[i] = 10;

  if (!auxNodo -> letra [26]){
    auxNodo -> letra [26] = (nodo*) 1;    /* indica último nodo de palavra */
    auxNodo -> filhos++;
  }

  return 1;
}


/*
int procura(nodo *N, char *palavra){
  nodo *aux;

  aux = get(N,palavra);

  if ((aux) && (aux -> letra [26])){
    printf("%s\n",aux -> palavra);
    return 1;
  }
  return 0;
}
*/



nodo* encheTrie(){
    int i,fim;   /* Vetor aonde será copiado um trecho do arq */
    char *palavra;
    raiz *root;
    nodo *no;
    FILE *entrada;

    root = criaTrie ();
    no = root -> primeiro;

    entrada = abreDicio();
    palavra = mallocc (30 * sizeof (int));

    palavra[0] = 1;

    for(i = 0; palavra[0] != 10 ; i++){   /* Não para até chegar no fim do FILE */

      palavra = copiaFile(entrada,palavra); /* extrai 1 palavra de FILE */
      inserePalavra (no,palavra);   /* Insere a palavra na TRIE */

      /* IMPRIME PALAVRA POR PALAVRA */
      for (fim = 0; palavra [fim] != 10; fim++){
        printf("%c",palavra[fim]);
      };
      printf ("\n");
    }
    fclose (entrada);
    free (palavra);
    return no;
}


int levenshtein(char *s, int ls, char *t, int lt)
{
        int a, b, c;

        /* if either string is empty, difference is inserting all chars
         * from the other
         */
        if (!ls) return lt;
        if (!lt) return ls;

        /* if last letters are the same, the difference is whatever is
         * required to edit the rest of the strings
         */
        if (s[ls] == t[ls])
                return levenshtein(s, ls - 1, t, lt - 1);

        /* else try:
         *      changing last letter of s to that of t; or
         *      remove last letter of s; or
         *      remove last letter of t,
         * any of which is 1 edit plus editing the rest of the strings
         */
        a = levenshtein(s, ls - 1, t, lt - 1);
        b = levenshtein(s, ls,     t, lt - 1);
        c = levenshtein(s, ls - 1, t, lt    );

        if (a > b) a = b;
        if (a > c) a = c;

        return a + 1;
}

/* Função auxiliar que acha o final de palavra */
nodo *get(nodo *N, char *palavra){
  int i, pos;
  nodo *pointer;

  i = 0;

  pointer = N;
  if (palavra [i] == 10){
    return NULL;
  } else {
    while ((palavra [i] != 10) && (pointer)){
      pos = INDICE_CHAR (palavra [i]);
      pointer = pointer -> letra [pos];
      i++;
    }
  }
  return pointer;
}


nodo *getReverse(nodo *N, char *palavra){
  int i, pos;
  nodo *pointer;

  i = 0;

  pointer = N;
  if (palavra [i] == 10){
    return NULL;
  } else {
    while ((palavra [i] != 10) && (pointer)){
      pos = INDICE_CHAR (palavra [i]);
      pointer = pointer -> letra [pos];
      i++;
    }
  }
  return pointer;
}

int procura(nodo *N, char *palavra, int dist){
  nodo *aux;
  char *lista;



  aux = get(N,palavra);
  if ((aux) && (aux -> letra [26])){
    printf("%s\n",aux -> palavra);
  }

  levenshtein(palavra, strlen(palavra), aux -> palavra, strlen(aux -> palavra));
  /* FAZER UMA FUNÇÃO GET REVERSE, POIS O aux VEM COM O ENDEREÇO DO ÚLTIMO NODO, A PARTIR DAÍ IR VOLTANDO PARA OS PAIS */


  if ((aux) && (aux -> filhos != 0))
    

  return 0; /* não tem */
}
