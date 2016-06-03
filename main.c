#include <stdio.h>
#include <stdlib.h>
#include "cabeca.h"

int main ( ) {

  int *lista,i;
  FILE *entrada;
  raiz *root;
  int *palavra;   /* Vetor aonde será copiado um trecho do arq */
  palavra = mallocc (15 * sizeof (int));

  entrada = abreDicio();

  lista = copiaFile(entrada,palavra);

  i = 0;
  lista = maiuscMinusc (lista);
  while (i < 15) {
    printf("%c",lista[i]);
    i++;
  }

  root = criaTrie ();
  root = criaNodo (root);


  fclose (entrada);
  free (palavra);

  return 0;
}
