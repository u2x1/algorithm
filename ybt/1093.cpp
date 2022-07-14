#include <cstdio>

int main() {
  double x; int n;
  scanf("%lf%d", &x, &n);
  double curr = 1;
  double ans = 1;
  for (int i = 0; i < n; ++i) {
    curr *= x;
    ans += curr;
  }
  printf("%.2f", ans);
  return 0;
}
