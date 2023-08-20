#include <stdio.h>
#include <math.h>
#define PI 3.14
#define f(x) (sin(x) + 1)

int main(void) {
  float angle, h, x, d;
  puts("Enter angle in degree");
  scanf("%f", &angle);
  puts("Enter interval h");
  scanf("%f", &h);
  x = PI/180 * angle;
  d = (f(x+h) - f(x)) / h;
  printf("Value of derivative is %f", d);
  return 0;
}
