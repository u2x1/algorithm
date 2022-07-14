#include <cstdio>

int main() {
  double x, a, y, b;
  scanf("%lf%lf%lf%lf", &x, &a, &y, &b);
  double rst = (a*x-b*y)/(a-b);
  printf("%.2f", rst);
  return 0;
}
