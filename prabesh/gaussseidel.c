#include <stdio.h>
#include <math.h>

int main(void) {
  int n, i, j, k;
  float sum, error, E[10], a[10][10], b[10], new_x[10] = {0}, old_x[10];
  puts("Enter the dimensions of the system");
  scanf("%d", &n);
  puts("Enter the coefficients row-wise:");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%f",&a[i][j]);
  puts("Enter B vector");
  for (i = 0; i < n; i++)
    scanf("%f", &b[i]);
  puts("Enter Tolerance Level");
  scanf("%f", &error);
  while (1) {
    for (i = 0; i < n; i++) {
      sum = b[i];
      for (j = 0; j < n; j++) {
        if (i!=j)
          sum = sum - a[i][j]*new_x[j];
      }
      old_x[i] = new_x[i];
      new_x[i] = sum/a[i][i];
      E[i] = fabs(new_x[i]-old_x[i])/fabs(new_x[i]);
    }
    for (i = 0; i < n; i++)
      if (E[i]>error)
        break;
    if (i==n) {
      break;
    } else continue;
  }
  puts("Solution");
  for (i = 0; i < n; i++)
    printf("x%d=%6.2f\n", i+1, new_x[i]);
  return 0;
}
