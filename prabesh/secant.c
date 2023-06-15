#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x) {
  // x^5 + x^3 + 3
  return x*x*x*x*x + x*x*x + 3;
}

void swap(double *x, double *y) {
  double temp = *x;
  *x = *y;
  *y = temp;
}

void secant(double (*f)(double), double a, double b, int nmax, double E) {
  double fa = (*f)(a);
  double fb = (*f)(b);

  if (fabs(fa) > fabs(fb)) {
    swap(&a, &b);
    swap(&fa, &fb);
  }
  printf("%d %8.4f %8.4f\n", 0, a, fa);
  printf("%d %8.4f %8.4f\n", 1, b, fb);

  for (int i = 2; i < nmax; i++) {
    if (fabs(fa) > fabs(fb)) {
      swap(&a, &b);
      swap(&fa, &fb);
    }
    double d = (b - a) / (fb - fa);
    b  = a;
    fb = fa;
    d  = d * fa;
    if (fabs(d) < E) {
      puts("Convergence!");
      printf("Root is %.4f.\n", a);

      exit(0);
    }
    a  = a - d;
    fa = (*f)(a);
    printf("%d %8.4f %8.4f\n", i, a, fa);
  }
}

int main(void) {
  secant(&f, -1.0, 1.0, 20, 0.000005);
  return 0;
}
