#include <cstdio>
#include <cmath>

int main() {
  int n, pep;
  double x, y;
  scanf("%d", &n);
  double sum = 0;
  for (int i = 0; i < n && scanf("%lf%lf%d", &x, &y, &pep); ++i) {
    sum += 2 * sqrt(x*x+y*y) / 50 + pep * 1.5;
  }
  printf("%.0f", ceil(sum));
  return 0;
}
