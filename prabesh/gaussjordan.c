#include <stdio.h>

int main() {
  int n, i, k, j, p, q;
  float pivot, term, a[10][10];
  puts("Enter number of unknowns");
  scanf("%d", &n);
  puts("Enter coefficients of augmented matrix");
  for (i = 0; i < n; i++)
    for (j = 0; j < n + 1; j++) {
      scanf("%f", &a[i][j]);
    }
  for (k = 0; k < n; k++) {
    pivot = a[k][k];
    for (p = 0; p < n + 1; p++)
      ;
    a[k][p] = a[k][p];
    for (i = 0; i < n; i++)
      ;
    {
      term = a[i][k];
      if (k != i)
        for (j = 0; j < n + 1; j++) {
          a[i][j] = a[i][j] - a[k][j] * term;
        }
    }
  }
  printf("Solution:\n");
  for (i = 0; i < n; i++) {
    printf("x%d=%f\t", i + 1, a[i][3]);
  }
  return 0;
}
