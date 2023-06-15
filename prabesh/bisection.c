#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sign(double x) {
  return (int) (x/fabs(x));
}

double f(double x) {
  // x^3 - 3x + 1
  return x*x*x - 3*x + 1;
}

/* @param f    <- function pointer
   @param a, b <- interval
   @param nmax <- maximum iterations to perform
   @param E    <- error bound

   @return root of f
 */

void bisection(double (*f)(double), double a, double b, int nmax, double E) {
  double fa = (*f)(a);
  double fb = (*f)(b);

  if (sign(fa)==sign(fb)) {
    printf("%f, %f\n", fa, fb);
    puts("function has same signs at a and b");
    exit(0);
  }

  double error = b - a;
  for (int i = 0; i < nmax; i++) {

    error = error / 2.0;
    double c = a + error;
    double fc = (*f)(c);
    printf("%d\t%.4f\t%.4f\t%.4f\n", i, c, fc, error);

    if (fabs(error) < E) {
      puts("convergence");
      printf("Root is %.4f\n", c);
      exit(0);
    }

    if (sign(fa) != sign(fc)) {
      b = c;
      fb = fc;
    } else {
      a = c;
      fa = fc;
    }
  }
}

int main(void) {
  bisection(&f, 0.0, 1.0, 20, 0.00005);
  return 0;
}
