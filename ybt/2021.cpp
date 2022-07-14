#include <cstdio>

int main() {
  int m, n, cache;
  scanf("%d%d", &m, &n);
  if (m < n) { cache = n; n = m; m = cache; }
  while (n != 0) {
    cache = m % n;
    m = n;
    n = cache;
  }
  printf("%d", m);
  return 0;
}
