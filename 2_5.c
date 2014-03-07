#include <stdio.h>
#define MAXCHAR 1000

int any(char s1[], char s2[]);

main() {
  int response;
  char s1[MAXCHAR] = "This is a string";
  char s2[MAXCHAR] = "string";
  response = any(s1, s2);
  printf("%d", response);
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j])
        return i;
    }
  }
  return -1;
}
