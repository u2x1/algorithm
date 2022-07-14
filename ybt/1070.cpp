#include <cstdio>

int main() {
  double x;
  int n;
  scanf("%lf%d", &x, &n);
  for (int i = 0; i < n; ++i) {
    x *= 1.001;
  }
  printf("%.4f", x);
  return 0;
}
