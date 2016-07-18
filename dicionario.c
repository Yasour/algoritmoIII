#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicionario.h"

 /* Função que avisa caso malloc devolva NULL */
void *mallocc (size_t nbytes){
  void *ptr;
  ptr = malloc (nbytes);
  if (ptr == NULL) {
    printf ("Socorro! malloc devolveu NULL!\n");
    exit (EXIT_FAILURE);
  }
  return ptr;
}
 /* Abre FILE do Dicionario corretamente */
FILE* abreDicio (){
  FILE *entrada;
  entrada = fopen ("dicionario.txt", "r");
  if (entrada == NULL) {
    printf("\nNão encontrei o arquivo dicionario.txt.\n");
    exit (EXIT_FAILURE);
  }
  return entrada;
}
/* Troca Maiúsculas -> Minúsculas */
char* maiuscMinusc(char* palavra){
  int i;
  for (i = 0; palavra [i] != 10; i++){

    if (palavra [i] >=65 && palavra [i] <= 90 ){
      palavra [i] += 32 ;
    }
  }
  return palavra;
}

int conferePalavra(char* palavra){
  int i, flag, tam;
  /* transforma maiusc por minusc */
  palavra = maiuscMinusc (palavra);
  tam = strlen(palavra);
  flag = 1;
  /* Limitei o tamanho para no máximo 14 letras */
  if(tam > 14){
    flag = 0;
  }
  for (i = 0; palavra[i] != 10 ; i++){
    /* Caso seja diferente de letras minusculas e pula linha */
    if (palavra [i] < 97 || palavra [i] > 123){
      flag = 0;
    }
  }
  if (flag == 1){
    /* CERTO */
    return 1;
  } else {
    /* ERRADO */
    return 0;
  }
}

 /* somente cria */
nodo* criaNo(nodo *p){
  int i ;
  nodo* no;
  no = mallocc (sizeof(nodo));
  for (i = 0; i <= 27; i++){
    no -> letra [i] = NULL ;
  }
  no -> filhos = 0;
  no -> palavra = NULL;
  return no;
}

 /* Função cria Raíz Trie */
raiz *criaTrie(){
  raiz *root;
  nodo* no;
  root = mallocc (sizeof(raiz));
  no = criaNo(NULL);
  root -> primeiro = no;
  return root;
}

 /* Recebe vetor com palavra conferida */
int inserePalavra(nodo* N, char* palav){
  int i, pos, tam;
  nodo *auxNodo;
  nodo *novoNodo;

  /*tamanho da palavra */
  tam = strlen(palav);
  /* exclui o new line */
  tam--;
  /* auxNodo é o primeiro nodo indicado pela RAIZ */
  auxNodo = N;

  for (i = 0; i < tam ; i++){
    /* posição 00~25*/
    pos = INDICE_CHAR (palav [i]);
    /* se existir */
    if (auxNodo -> letra [pos]){
      auxNodo -> filhos++;
      auxNodo = auxNodo -> letra [pos];
    } else {
      novoNodo = criaNo(auxNodo);
      auxNodo -> letra [pos] = novoNodo;
      auxNodo -> filhos ++;
      novoNodo -> palavra = NULL;
      auxNodo = novoNodo;
    }
  }
  /* aloca o tamanho certo de cada palavra */
  auxNodo -> palavra = mallocc ((tam + 1) * (sizeof(char)));

 /* copia o char da palavra completa no último nodo */
  for (i = 0; i < tam ; i++){
    auxNodo -> palavra[i] = palav[i];
  }
  auxNodo->palavra[i] = '\0';

  if (!auxNodo -> letra [26]){
     /* indica último nodo de palavra */
    auxNodo -> letra [26] = (nodo*) 1;
  }
  return 1;
}

nodo* encheTrie(){
    int i=0;
    char *palavra;
    raiz *root;
    nodo *no;
    FILE *entrada;

    /*  a raíz da árvore */
    root = criaTrie ();
     /* no recebe o primeiro nodo da raíz*/
    no = root -> primeiro;

    entrada = abreDicio();
    palavra = mallocc (30 * sizeof (int));

    while (fgets(palavra, 30, entrada)){

      i = conferePalavra(palavra);

      if (i == 1){
      /*  printf("%s",palavra);       Aqui ele imprime palavras certas*/
        inserePalavra (no,palavra);
      }
    }

    fclose (entrada);
    return no;
}

/* Função retorna com nível levenshtein entre 2 strings */
int levenshtein(char *s1, char *s2) {

    int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    s1len++;
    s2len++;
    /*printf("s1len: %d, s2len: %d\n",s1len, s2len);*/
    int matrix[s2len][s1len];
    matrix[0][0] = 0;

    for (x = 1; x <= s2len; x++){
        matrix[x][0] = matrix[x-1][0] + 1;
    }
    for (y = 1; y <= s1len; y++){
        matrix[0][y] = matrix[0][y-1] + 1;
    }
    for (x = 1; x <= s2len; x++){
        for (y = 1; y <= s1len; y++){
            matrix[x][y] = MIN3(matrix[x-1][y] + 1, matrix[x][y-1] + 1,
            matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));
        }
    }

    return(matrix[s2len][s1len]);
}

int confereLeven(nodo *no, char *pal, int leven){
  int num = 0;
  /* Confere se há palavra neste nodo */

  if (no -> palavra){

    num = levenshtein (no -> palavra, pal);
    /*printf("Leven: %d\n",num);
    printf("qual palavra? %s \n",no->palavra);
    printf("num: %d, leven %d\n",num,leven);*/
    if ((num > 0) && (num <= leven)){

      /* retorna 1 se a palavra servir */
      /*printf("palavra: %s \n", no->palavra);*/
      return 1;
    }
  }
  return 0;
}

int procura(FILE *saida, nodo *n, char *pal, int leven, int cont){

  int i, num, len;
  nodo* no;
  no = n;
  if (no){
    /* Confere se há palavra neste nodo */
    num = confereLeven(no, pal,leven);
  /*  printf("leven %d",num);*/
    /* Se a palavra servir */
    if(num == 1){
      /*printf("\nescreveu 1\n");*/
      fprintf(saida,"%s ",no -> palavra);
      cont++;
      /*printf("contagem: %d\n",cont);*/
      num = 0;
      /* se passar de 20 palavras, termina */
    }
    if (cont >= 20){
      return cont;
    }
  }
  if(no){
  /*  printf("filhos? %d\n",no->filhos);*/
    if ((no -> filhos) > 0){
      for (i = 0; i <= 25; i++){
        if ((no -> letra[i])){
        /*  printf("i: %d\n",i);*/
          cont = procura(saida, no -> letra[i], pal, leven, cont);
          if(cont >= 20){
            return cont;
          }
        }
      }
    }
  }
  return cont;
}
