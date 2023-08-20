#include <stdio.h>
#define f(x) (x * x * x + 3 * x * x)

int main(void) {
  float a, h, x0, xn, fx0, fxn, term, I;
  int i, k;
  puts("Enter the limits (x0, xn)");
  scanf("%f%f", &x0, &xn);
  puts("Enter the number of segments");
  scanf("%d", &k);
  h = (xn - x0) / k;
  fx0 = f(x0);
  fxn = f(xn);
  term = f(x0) + f(xn);
  for (i = 1; i <= k-1; i++) {
    a = x0 + i * h;
    if (i % 3 != 0)
      term += 3*f(a);
    else term += 2*f(a);
  }
  I = (3*h)/8 * term;
  printf("Value of integration is %f", I);
  return 0;
}
