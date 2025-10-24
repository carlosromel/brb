/**
 * Copyleft (c) 2025 Carlos Romel Pereira da Silva, carlos.romel@gmail.com
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "brb.h"

int incorporar(char buffer[], char elemento[], int debug);

char *brb(char c[], int debug) {
  int  bp      = 0;
  int  t       = strlen(c);
  char *buffer = (char*) malloc(sizeof(char) * 10240);

  for (int n = 0; n < t; ++n) {
    int encontrado = -1;

    if (isalpha(c[n])) {
      int e;
      for (e = 0; e < 116; ++e) {
        if (toupper(c[n]) == toupper(elementos[e][0])) {
          if ((e + 1) < 116
	      && strlen(elementos[e]) == 1
	      && toupper(c[n])        != toupper(elementos[e + 1][0])) {
            encontrado = e;
          } else if (strlen(elementos[e]) > 1
		     && toupper(c[n + 1]) == toupper(elementos[e][1])) {
            encontrado = e;
            ++n;
          } else {
            for (int ee = e + 1; ee < 116; ++ee) {
              if (strlen(elementos[ee]) > 1
		  && toupper(c[n])     == toupper(elementos[ee][0])
		  && toupper(c[n + 1]) == toupper(elementos[ee][1])) {
                encontrado = ee;
                ++n;

                break;
              }
            }
          }

          if (encontrado >= 0) {
	    bp += incorporar(buffer, elementos[encontrado], debug);
          }

	  break;
        }
      }

      if (encontrado == -1) {
	if (strlen(elementos[e]) == 1) {
	  bp += incorporar(buffer, elementos[e], debug);
	} else {
	  buffer[bp++] = c[n];
	}
      }
    } else {
      buffer[bp++] = c[n];
    }
  }

  return buffer;
}

int incorporar(char buffer[], char elemento[], int debug) {
  char mascara[20] = "";
  char *retorno    = (char*) malloc(sizeof(char) * (sizeof(mascara) + strlen(elemento)));

  if (debug == 1) {
    strcat(mascara, "[%s]");
  } else {
    strcat(mascara, "\\033[0;32m%s\\033[0m");
  }

  sprintf(retorno, mascara, elemento);
  strcat(buffer, retorno);

  return strlen(retorno);
}
