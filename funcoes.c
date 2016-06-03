#include <stdio.h>
#include <stdlib.h>
#include "cabeca.h"

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

int* maiuscMinusc(int* entrada){       /* Troca Maiúsculas -> Minúsculas */
  int i;
  i = 0;
  while (entrada[i] != '\0'){
    if (entrada [i] >=65 && entrada [i] <= 90 ){
      entrada [i] += 32 ;              /* Soma 32 ao valor original */
    }
    i++;
  }
  return entrada;
}

int* monoMaiuscMinusc(int* entrada,int i){       /* Troca para 1 char */
  if (entrada [i] >=65 && entrada [i] <= 90 )
    entrada [i] += 32 ;              /* Soma 32 ao valor original */
  return entrada;
}

int conferePalavra(int* palavra){
  int i = 0;
  palavra = maiuscMinusc (palavra);

  do{
    if (palavra [i] <= 97 || palavra [i] >= 123 || palavra [i] != 10){  /* Caso seja diferente de letras minusculas e pula linha */
      return 0; /* Errado */
    }
    else{
      return 1; /* CERTO */
    }
    i++;
  }while (palavra[i] != '\0');    /* até final vetor */
}

int *copiaFile(FILE *entrada, int* palavra){         /* .txt -> vetor */

  int i = 0;

  do{
    palavra [i] = fgetc (entrada);  /* copie do .txt 1 char */

    if (palavra [i] == EOF) {         /* fim FILE */
      return palavra;
    }

    i++;
  }while (palavra [i] != 10);

  return palavra;                     /* Vetor com o trecho */
}

raiz *criaTrie(){                     /* Função cria Raíz Trie */
  raiz *root;
  root = mallocc (sizeof(raiz));
  return root;
}

raiz* criaNodo(raiz *root){           /* somente cria */
  nodo* no;
  no = mallocc (sizeof(nodo));
  root -> primeiro = no;              /* primeiro nó adicionado na raíz */
  return root;                        /* retornará o endereço raiz */
}

int calculaLetra (int* palavra){  /* Calcula endereço correspondente no vetor */
  int i;
  i = (palavra [0] - 97);           /* Correspondente ao vetor de 0 ~ 25 */
  return i;
}

raiz* inserePalavra(raiz* root, int* palavra){    /* Recebe vetor com lista de palavras*/
  if (root -> primeiro == NULL){      /* Caso Seja o primeiro nodo a ser incluido */
    root = criaNodo (root);
  }
  /* FUNÇÃO PROCURA ROOT UMA LETRA */
  return root;
}
