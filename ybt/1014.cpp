#include <cstdio>

#define M_PI 3.14159

int main() {
  double a;
  scanf("%lf", &a);
  printf("%.4f %.4f %.4f", 2*a, 2*a*M_PI, a*a*M_PI);
  return 0;
}
