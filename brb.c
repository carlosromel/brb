/**
 * Copyleft (c) 2025 Carlos Romel Pereira da Silva, carlos.romel@gmail.com
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "brb.h"

int incorporar(char **buffer, size_t *capacity, size_t *bp, const char *elemento, int debug);

char *brb(char c[], int debug) {
  size_t bp       = 0;
  size_t t        = strlen(c);
  size_t capacity = (t * 12) + 1;
  char *buffer    = (char*) malloc(sizeof(char) * capacity);

  if (!buffer) {
    return NULL;
  }

  buffer[0] = '\0';

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
	    incorporar(&buffer, &capacity, &bp, elementos[encontrado], debug);
          }

	  break;
        }
      }

      if (encontrado == -1) {
	buffer[bp++] = c[n];
	buffer[bp] = '\0';
      }
    } else {
      buffer[bp++] = c[n];
      buffer[bp] = '\0';
    }
  }

  return buffer;
}

int incorporar(char **buffer, size_t *capacity, size_t *bp, const char *elemento, int debug) {
  const char *mascara = debug == 1 ? "[%s]" : "\033[0;32m%s\033[0m";
  int needed = snprintf(NULL, 0, mascara, elemento);

  if (needed < 0) {
    return 0;
  }

  if ((*bp + (size_t) needed + 1) > *capacity) {
    size_t new_capacity = (*capacity) * 2;
    if (new_capacity < (*bp + (size_t) needed + 1)) {
      new_capacity = *bp + (size_t) needed + 1;
    }
    char *new_buffer = (char *) realloc(*buffer, new_capacity);
    if (!new_buffer) {
      return 0;
    }
    *buffer = new_buffer;
    *capacity = new_capacity;
  }

  snprintf(*buffer + *bp, *capacity - *bp, mascara, elemento);
  *bp += (size_t) needed;

  return needed;
}
