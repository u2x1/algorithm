#include <cstdio>

int main() {
  int n, rst = 0;
  scanf("%d", &n);
  bool flag = 0;
  if (n < 0) { n = -n; flag = 1; }
  for (int i = 1; i <= n; i *= 10) {
    rst = rst * 10 + (n / i % 10);
  }
  if (flag) { rst = -rst; }
  printf("%d", rst);
  return 0;
}
