#include <stdio.h>
#include <math.h>
#define g(x) ((a3*x*x*x+a2*x*x+a0) / (-a1))
float a3, a2, a1, a0;

int main(void) {
  float x0, x1, E, Er;
  puts("Enter the coefficients a3, a2, a1, a0");
  scanf("%f%f%f%f", &a3, &a2, &a1, &a0);
  puts("Enter the initial guess and error tolerance");
  scanf("%f%f", &x0, &E);
  while(1) {
    x1 = g(x0);
    Er = fabs((x1-x0) / x1);
    if (Er < E) {
      printf("The Root is %f", x1);
      break;
    }
    x0 = x1;
  }
  return 0;
}
