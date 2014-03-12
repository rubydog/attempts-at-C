#include <stdio.h>
#include <string.h>

int strrindex(char s[], int t);

int strrindex(char s[], int t) {

  for (int i = strlen(s)-1; i >= 0; i--) {
    if (s[i] == t)
      return ++i;
  }

  return -1;
}

main() {
  char s[1000] = "This is string";
  int t = 's';

  int result = strrindex(s, t);
  printf("%d", result);
}
