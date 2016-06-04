#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

int main ( ) {

  int *lista,i;
  FILE *entrada;
  raiz *root;
  int *palavra;   /* Vetor aonde será copiado um trecho do arq */
  palavra = mallocc (15 * sizeof (int));

  entrada = abreDicio();

  palavra = copiaFile(entrada,palavra);

  i = 0;
  /*palavra = maiuscMinusc (palavra);*/
  while (i < 15) {
    printf("%c",palavra[i]);
    i++;
  }

  root = criaTrie ();
  root = criaNodo (root);


  fclose (entrada);
  free (palavra);

  return 0;
}
