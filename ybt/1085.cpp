#include <cstdio>

int main() {
  double h;
  scanf("%lf", &h);
  double s = -h;
  for (int i = 0; i < 10; ++i) {
    s += 2*h;
    h /= 2;
  }
  printf("%g\n%g", s, h);
  return 0;
}
