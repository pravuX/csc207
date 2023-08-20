#include <math.h>
#include <stdio.h>
#define y1(X) (2 + (x)-2 / 3.0 * pow(x, 3))
#define y2(x) (2 + (x) + pow(x, 2) - 2 / 3.0 * pow(x, 3) + pow(x, 4) / 4)
#define y3(x) (2 + (x) + pow(x, 2) - pow(x, 4) / 3 - pow(x, 5) / 15)

int main() {
  float x, x0, y0, y, ny, er;
  puts("Enter initial values of x & y");
  scanf("%f%f", &x0, &y0);
  puts("Enter x at which function to be evaluated");
  scanf("%f", &x);
  y = y0;
  y = y0 + y1(x);
  y = y0 + y2(x);
  y = y0 + y3(x);
  printf("Functional value at x=%f is %f\n", x, y);

  return 0;
}
