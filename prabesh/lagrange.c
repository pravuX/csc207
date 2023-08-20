#include <stdio.h>

int main() {
  float x_data[100], y_data[100], x, inter_poly = 0, li;
  int i, j, n;
  printf("Enter number of data: ");
  scanf("%d", &n);
  printf("Enter data:\n");
  for (i = 0; i < n; i++) {
    printf("x[%d] = ", i);
    scanf("%f", &x_data[i]);
    printf("y[%d] = ", i);
    scanf("%f", &y_data[i]);
  }
  printf("Enter interpolation point: ");
  scanf("%f", &x);
  for (i = 0; i < n; i++) {
    li = 1;
    for (j = 0; j < n; j++) {
      if (i != j) {
        li = li * (x - x_data[j]) / (x_data[i] - x_data[j]);
      }
    }
    inter_poly += li * y_data[i];
  }
  printf("Interpolated value at %.3f is %.3f.", x, inter_poly);
}
