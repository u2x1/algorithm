#include <cstdio>

#define M_PI 3.14159265358979323846

int main() {
  int h, r;
  scanf("%d%d", &h, &r);
  double v = M_PI * h * r * r / 1000;
  int rst = 20 / v;
  if (rst * v < 20) { printf("%d", rst + 1); }
  else { printf("%d", rst); }
  return 0;
}
