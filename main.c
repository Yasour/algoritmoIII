#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"

int main (int argc, char *argv[] ) {
/*
  int i;
  FILE *entrada;
  raiz *root;
  int *palavra;
  nodo *no;
  printf("%d\n",argc);

  palavra = mallocc (15 * sizeof (int));

  entrada = abreDicio();

  palavra = copiaFile(entrada,palavra);

  for (i = 0; palavra [i] != 10; i++){
    printf("%c",palavra[i]);
  }

  printf("\napós impressão\n");

  root = criaTrie ();

  no = root -> primeiro;

  inserePalavra (no,palavra);
  printf("resultado procura: %d\n",(int)procura(no,palavra));


  fclose (entrada);
  free (palavra);
*/
  printf("palavras adicionadas:%d\n", encheTrie());

  

  return 0;
}
