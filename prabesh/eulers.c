#include <stdio.h>
#define f(x, y) ( 2 * y / x )

int main(void) {
  float x, xp, x0, y0, y, h;
  puts("Enter intitial values x0, y0");
  scanf("%f%f", &x0, &y0);
  puts("Enter x at which function is to be evaluated");
  scanf("%f", &xp);
  puts("Enter the step size");
  scanf("%f", &h);
  y = y0;
  x = x0;
  for (x = x0; x < xp; x+=h)
    y+=f(x, y) * h;
  printf("Functional value at %f is %f", xp, y);
  return 0;
}
