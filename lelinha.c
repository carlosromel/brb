/**
 * Copyleft (c) 2025 Carlos Romel Pereira da Silva, carlos.romel@gmail.com
 */
#include <stdio.h>

int lelinha (char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1; ++i) {
    if ((c = getchar ()) != EOF && c != '\n') {
      s[i] = c;
    } else {
      break;
    }
  }

  if (c == '\n') {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}
