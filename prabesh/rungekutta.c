#include <stdio.h>

float f(float x, float y) { return 2 * x + y;}

int main(void) {
  float x, xp, x0, y0, y, h, m1, m2, m3, m4;
  puts("Enter initial values of x and y");
  scanf("%f%f", &x0, &y0);
  puts("Enter x at which function is to be evaluated");
  scanf("%f", &xp);
  puts("Enter the step size");
  scanf("%f", &h);
  y = y0;
  for(x = x0; x < xp; x+=h) {
    m1 = f(x, y);
    m2 = f(x+h/2, y+h/2*m1);
    m3 = f(x+h/2, y+h/2*m2);
    m4 = f(x+h, y+h*m3);
    y  = y + h / 6 * (m1 + 2*(m2+m3) + m4);
  }
  printf("The functional value at %f is %f", xp, y);
  return 0;
}
