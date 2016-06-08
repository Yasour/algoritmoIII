#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"

int main ( ) {

  int i;
  FILE *entrada;
  raiz *root;
  int *palavra;   /* Vetor aonde será copiado um trecho do arq */
  nodo *no;
  palavra = mallocc (15 * sizeof (int));

  entrada = abreDicio();

  palavra = copiaFile(entrada,palavra);

  i = 0;
  /*palavra = maiuscMinusc (palavra);*/
  while (i < 15) {
    printf("%c",palavra[i]);
    i++;
  }
  printf("\n");
  root = criaTrie ();
  root = criaNodo (root);
  no = root -> primeiro;

  inserePalavra (no,palavra);


  fclose (entrada);
  free (palavra);

  return 0;
}
