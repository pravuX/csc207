#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x) {
  // x^3 -2x^2 + x - 3
  return ((x - 2.0)*x + 1.0)*x - 3.0;
}

double f_prime(double x) {
  // 3x^2 - 4x + 1
  return (3.0*x - 4.0) * x + 1.0;
}
/*
  @param f, f_prime <- function, first derivative
  @param x          <- Initial Guess of root
  @param nmax       <- Max number of iterations to perform
  @param ep, del    <- Error bound
*/

void newton(double (*f)(double), double (*f_prime)(double),
            float x, int nmax, float ep, float del) {
  float fx = (*f)(x);
  printf("%d %8.4f %8.4f\n", 0, x, fx);
  for (int i = 1; i < nmax; i++) {
    float fp = (*f_prime)(x);
    if (fabs(fp) < del) {
      puts("Small derivate.");
      exit(0);
    }
    float d = fx / fp;
    x = x - d;
    fx = (*f)(x);
    printf("%d %8.4f %8.4f\n", i, x, fx);
    if (fabs(d) < ep) {
      puts("Convergence!");
      printf("Root is %.4f.", x);
      exit(0);
    }
  }
}

int main(void) {
  newton(&f, &f_prime, 3, 20, 0.0005, 0.01);
  return 0;
}
