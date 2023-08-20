#include <stdio.h>

float f(float x, float y) {
  return 2 * y / x;
}

int main(void) {
  float x, xp, x0, y0, y, h, m1, m2;
  puts("Enter initial values x0 y0");
  scanf("%f%f", &x0, &y0);
  puts("Enter x at which function is to be evaluated");
  scanf("%f", &xp);
  puts("Enter the step size");
  scanf("%f", &h);
  y = y0;
  for (x = x0; x < xp; x+=h) {
    m1 = f(x, y);
    m2 = f(x+h, y+h*m1);
    y  = y + h * (m1 + m2) * 0.5;
  }
  printf("Functional value at %f is %f", xp, y);
  return 0;
}
