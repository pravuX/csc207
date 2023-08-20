#include <stdio.h>

int main(void) {
  int n, i, j, k;
  float a = 0, b = 0, x[10], y[10], xp;
  float sx = 0, sy = 0, sxy = 0, sx2 = 0;
  puts("Enter the number of points:");
  scanf("%d", &n);
  puts("Enter the sample points:");
  for (i = 0; i < n; i++) {
    scanf("%f%f", &x[i], &y[i]);
  }
  puts("Enter value to be approximated at:");
  scanf("%f", &xp);
  for (i = 0; i < n; i++) {
    sx += x[i];
    sy += y[i];
    sxy += x[i] * y[i];
    sx2 += x[i] * x[i];
  }
  b = ((n * sxy) - (sx * sy)) / ((n * sx2) - (sx * sx));
  a = (sy / n ) - (b * sx/n);
  printf("The fitted line is y = %.3fx + %.3f\n", a, b);
  printf("The approx. value at %.3f is %.3f", xp, a * xp + b);
  return 0;
}
