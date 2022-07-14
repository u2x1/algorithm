#include <cstdio>

int main() {
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  a %= b;
  if (a == 0) { printf("0"); return 0; }
  int ret;
  for (int i = 1; i <= n; ++i) {
    a *= 10;
    if (i == n) { ret = a / b; }
    a %= b;
  }
  printf("%d", ret);
  return 0;
}
