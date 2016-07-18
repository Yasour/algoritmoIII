#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"

int main (int argc, char *argv[] ) {

  char *pal, *palavra;
  FILE *saida, *entrada;
  int j, leven, cont;
  nodo *no;

  /* palavras a serem pesquisadas*/
  entrada = fopen (argv[1], "r");
  /* resultado */
  saida = fopen (argv[2], "w");
  /* Insere as palavras na Trie */
  no = encheTrie ();

  palavra = mallocc (30 * sizeof (int));
  pal = mallocc (30 * sizeof (int));

  while (fgets(pal, 30, entrada)){
    pal = maiuscMinusc(pal);
    for (j=0; pal[j] != 32 ; j++){
      palavra[j] = pal[j];
    }
    palavra[j] = '\0';
    fprintf(saida,"%s: ",palavra);
    /* leven é o nível levenshtein */
    leven = (pal[++j]-48);
    cont = 0;
    cont = procura(saida, no, palavra, leven, cont);
    /*printf("\nNumero de palavras achadas: %d\n",cont);*/
    fprintf(saida,"\n");
  }


  fclose (entrada);
  fclose (saida);


  return 0;

}
