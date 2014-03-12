#include <stdio.h>
#include <ctype.h>
#include <string.h>
void atof(char s[]);

void atof(char s[]) {
  double val, power;
  int i, exp, sign, exponential_sign = 1;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-' ? -1 : 1);

  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = val * 10.0 + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  val = sign*val/power;
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  exponential_sign = (s[i] == '-' ? -1 : 1);
  if (s[i] == '+' || s[i] == '-')
    i++;
  while(isdigit(s[i])) {
    exp = 10.0*exp + (s[i] - '0');
    i++;
  }

  

  printf("%lf", val/power);
  /* printf("%lf", power); */
  /* if (exponential_sign == -1) */
  /*   printf("%lf, %lf, %lf", val, power, (sign*val/power)); */
  /* else */
    /* printf("%lf, %lf, %lf", val, power, (sign*val*power)); */
// check for e
// check for sign after e
// if sign set flag
// 

}

main() {
  char s[1000] = " 45.34e-1 Hello, world!";
  atof(s);

}
