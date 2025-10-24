/**
 * Copyleft (c) 2025 Carlos Romel Pereira da Silva, carlos.romel@gmail.com
 */
#include <stdio.h>

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "lelinha.h"
#include "brb.h"

#define MAX_LINHA 1000 /* Tamanho máximo da linha */

int main(int argc, char *argv[]) {
    char linha[MAX_LINHA];
    int  t     = 0;
    int  debug = 0;

    for (int n = 0; n < argc; ++n) {
      if (strcmp(argv[n], "-d") == 0 ||
	  strcmp(argv[n], "--debug") == 0) {
	debug = 1;
	break;
      }
    }
 
    while((t = lelinha (linha, MAX_LINHA)) > 0) {
      printf("%s", brb(linha, debug));
    }

    return 0;
}
