#include <cstdio>
#include <cmath>

int main() {
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);
  double p = (a+b+c)/2;
  double s = sqrt(p*(p-a)*(p-b)*(p-c));
  printf("%.3f", s);

  return 0;
}
