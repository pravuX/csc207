#include <math.h>
#include <stdio.h>
#define g(x, y) ((x) * (y))

int main(void) {
  int n, i, j, k;
  float sum, error, E[10], a[10][10] = {0}, b[10] = {0}, new_x[10] = {0},
                           old_x[10], t4[4], h;
  puts("Enter Dimension of plate.");
  scanf("%d", &n);
  puts("Enter Dimension of grid.");
  scanf("%f", &h);
  puts("Enter temperatues: tl, tr, tb and tu.");
  for (i = 0; i < 4; i++)
    scanf("%f", &t4[i]);
  for (i = 0; i <= n; i++) {
    a[i][i] = -4;
    for (j = 0; j <= n; j++) {
      if (i != j && j != (n - i))
        a[i][j] = 1;
    }
  }
  k = 0;
  for (i = 1; i < n; i++) {
    for (j = 1; j < n; j++) {
      b[k++] = h * h * g(i, j);
    }
  }
  k = 0;
  for (i = 0; i < (n - 1); i++) {
    for (j = 0; j < (n - 1); j++) {
      if ((i - 1) == -1)
        b[k] -= t4[0];
      if ((i + 1) == (n - 1))
        b[k] -= t4[1];
      if ((j - 1) == -1)
        b[k] -= t4[2];
      if ((j + 1) == (n - 1))
        b[k] -= t4[3];
      k++;
    }
  }
  puts("Enter the Error tolerance");
  scanf("%f", &error);
  while (1) {
    for (i = 0; i <= n; i++) {
      sum = b[i];
      for (j = 0; j <= n; j++) {
        if (i != j)
          sum = sum - a[i][j] * new_x[j];
      }
      old_x[i] = new_x[i];
      new_x[i] = sum / a[i][i];
      E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);
    }
    for (i = 0; i <= n; i++)
      if (E[i] > error)
        break;
    if (i == (n + 1)) {
      break;
    } else
      continue;
  }
  puts("Solution");
  for (i = 0; i <= n; i++)
    printf("x%d = %.3f\n", i + 1, new_x[i]);

  return 0;
}
