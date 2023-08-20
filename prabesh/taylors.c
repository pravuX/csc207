#include <stdio.h>
#include <math.h>

int fact(int n) {
  if (n == 1)
    return 1;
  else
    return n * fact(n - 1);
}

int main() {
  float x, x0, y0, y, fdy, sdy, tdy;
  puts("Enter initial values of x & y");
  scanf("%f%f", &x0, &y0);
  puts("Enter x at which function to be evaluated");
  scanf("%f", &x);
  fdy = pow(x0, 2) + pow(y0, 2);
  sdy = 2 * (x0) + 2 * (y0)*fdy;
  tdy = 2 + 2 * y0 * sdy + 2 * fdy * fdy;
  float h = x - x0;
  y = y0 + h * fdy + pow(h, 2) * sdy / fact(2)
    + pow(h, 3) * tdy / fact(3);
  printf("Functional value at %.3f is %.3f", x, y);
  return 0;
}
