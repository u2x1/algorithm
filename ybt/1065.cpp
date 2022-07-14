#include <cstdio>

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  if (m%2 == 0) { ++m; }
  int sum = 0;
  for (; m <= n; m += 2) {
    sum += m;
  }
  printf("%d", sum);
  return 0;
}
