#include <stdio.h>
#include <math.h>
#define f(x) (1 / (x)) // the function to be integrated

int main(void) {
  float x0, xn, T[10][10], h, sum, sl, a;
  int i, k, c, r, m, p, q;
  puts("Enter upper and lower limits"); // e.g. 1 2
  scanf("%f%f", &x0, &xn);
  puts("Enter p & q of required T(p, q)"); // e.g. 2 2
  scanf("%d%d", &p, &q);
  h = xn - x0;
  T[0][0] = h / 2 * (f(x0)+f(xn));
  for (i = 1; i <= p; i++) {
    sl = pow(2, i-1);
    sum = 0;
    for (k = 1; k <= sl; k++) {
      a = x0 + (2 * k - 1) * h / pow(2, i);
      sum = sum + f(a);
    }
    T[i][0] = T[i - 1][0] / 2 + sum * h / pow(2, i);
  }
  for (c = 1; c <= p; c++) {
    for (k = 1; k <= c && k <= q; k++) {
      m = c - k;
      T[m+k][k] = (pow(4, k) * T[m+k][k-1] - T[m+k-1][k-1]) / (pow(4, k) - 1);
    }
  }
  printf("The Romberg Estimate of Integral is %f", T[p][q]);
  return 0;
}
