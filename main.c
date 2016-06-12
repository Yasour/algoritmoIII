#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"

int main (int argc, char *argv[] ) {
/*
  char *s1 = "ivo0";
  char *s2 = "iva";

  printf("distance between `%s' and `%s': %d\n", s1, s2,
          levenshtein(s1, strlen(s1), s2, strlen(s2)));*/
  char *pal;

  int i= 1;
  nodo *no;
  no = encheTrie ();
  pal = malloc (30*(sizeof(char)));
  pal[0] = 'a';
  pal[1] = 'l';
  pal[2] = 'a';
  pal[3] = 'i';
  pal[4] = 'r';
  pal[5] = 10;
  procura (no,  pal, i);




  return 0;

}
