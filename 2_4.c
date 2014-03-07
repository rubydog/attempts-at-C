#include <stdio.h>
#define MAXCHAR 1000

void squeeze(char s1[], char s2[]);

main() {
 // char s1[MAXCHAR], s2[MAXCHAR];
  char s1[MAXCHAR] = "This is a string";
  char s2[MAXCHAR] = "i a";
  squeeze(s1, s2);
  printf("%s", s1);
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;

  for (i = k = 0; s1[i] != '\0'; i++) {
    s1[k++] = s1[i];
    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) { 
        --k;
        break;
     }
    }
  }
  s1[k] = '\0';
}

