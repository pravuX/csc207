#include <stdio.h>
#include <math.h>
#define f(x) 2*exp(x)

int main(void) {
  float h, x, d;
  puts("Enter value at which derivative is needed");
  scanf("%f", &x);
  puts("Enter interval h");
  scanf("%f", &h);
  d = (f(x) - f(x - h))/h;
  printf("Value of Derivative = %f", d);
  return 0;
}
