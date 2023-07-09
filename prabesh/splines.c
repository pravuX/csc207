#include <math.h>
#include <stdio.h>

int main() {
  int n, i, j, xp;
  puts("Enter number of points");
  scanf("%d", &n);
  n--;
  float x[n + 1], a[n + 1], h[n], A[n], l[n + 1], u[n + 1], z[n + 1], c[n + 1],
      b[n], d[n], val;
  puts("Enter the points");
  for (i = 0; i < n + 1; ++i)
    scanf("%f", &x[i]);
  for (i = 0; i < n + 1; ++i)
    scanf("%f", &a[i]);

  puts("Enter the point to be interpolated:");
  scanf("%d", &xp);

  for (i = 0; i <= n - 1; ++i)
    h[i] = x[i + 1] - x[i];

  for (i = 1; i <= n - 1; ++i)
    A[i] = 3 * (a[i + 1] - a[i]) / h[i] - 3 * (a[i] - a[i - 1]) / h[i - 1];

  l[0] = 1;
  u[0] = 0;
  z[0] = 0;

  for (i = 1; i <= n - 1; ++i) {
    l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * u[i - 1];
    u[i] = h[i] / l[i];
    z[i] = (A[i] - h[i - 1] * z[i - 1]) / l[i];
  }

  l[n] = 1;
  z[n] = 0;
  c[n] = 0;

  for (j = n - 1; j >= 0; --j) {
    c[j] = z[j] - u[j] * c[j + 1];
    b[j] = (a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
    d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
  }
  for (i = 0; i < n - 1; i++) {
    if (xp <= x[i])
      break;
  }
  float tmp = xp - x[i];
  val = a[i] + b[i] * (tmp) + c[i] * pow(tmp, 2) + d[i] * pow(tmp, 3);
  printf("Interpolated value at %d: %.3f", xp, val);
  return 0;
}
