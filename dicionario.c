#include <stdio.h>
#include <stdlib.h>
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

  return 0; /* SE CHEGOU AQUI, ALGO DEU ERRADO */
}

int *copiaFile(FILE *entrada, int* palavra){         /* .txt -> vetor */

  int i = 0;
  int j;

  while (i < 15){
    palavra [i] = fgetc (entrada);  /* copie do .txt 1 char */


    if (palavra [i] == EOF || palavra [i] == 10) {         /* fim FILE ou fim palavra */
      /* ADICIONAR AQUI A FUNÇAO CONFERE palavra
      CASO NECESSÁRIO, RETOMAR O WHILE NO ZERO CASO CONTRARIO
      SETAR i = 15 */
      j = conferePalavra(palavra);
      if (j == 0){
        i = 0;
      }else
      if (j == 1){
        return palavra;         /* Aqui fará com que saia do laço WHILE */
      }
    }
    i++;
  }

  return palavra;                     /* Vetor com o trecho */
}

raiz *criaTrie(){                     /* Função cria Raíz Trie */
  raiz *root;
  root = mallocc (sizeof(raiz));
  return root;
}

raiz* criaNodo(raiz *root){           /* somente cria */
  int i = 0 ;
  nodo* no;
  no = mallocc (sizeof(nodo));

  while (i < 27){
    no -> letra [i] = 0 ;             /* valor inicial do vetor 0 */
    i ++ ;
  }

  root -> primeiro = no;              /* primeiro nó adicionado na raíz */
  return root;                        /* retornará o endereço raiz */
}

int calculaLetra (int* palavra){  /* Calcula endereço correspondente no vetor */
  int i;
  i = (palavra [0] - 97);           /* Correspondente ao vetor de 0 ~ 25 */
  return i;
}

int procuraCelula (nodo* no, int i){
  if (no -> letra [i] == 0){
    return 0;     /* VAZIO */
  }
  else {
    return 1;      /* CHEIO */
  }
}

raiz* inserePalavra(raiz* root, int* palavra){    /* Recebe vetor com lista de palavras*/
  int i ;
  nodo *primeiroNodo;   /* vou inserir o primeiro nodo indicado pela RAIZ */
  nodo *novoNodo;

  if (root -> primeiro == NULL){      /* Caso Seja o primeiro nodo a ser incluido */
    root = criaNodo (root);
  }

  primeiroNodo = root -> primeiro;


  i = procuraCelula ( primeiroNodo, calculaLetra(palavra)); /* procuraCelula irá indicar se está ocupado ou não o vetor em dada celula */
  if ( i == 0 ){      /* Não possui palavras que iniciam nesta letra */
    novoNodo = mallocc (sizeof (nodo));
  }
  return root;
}
