#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int i = 1, count = 0;
  if (n > 999) {
    int x = n / 1000;
    if (x > 2) { i = x * 1000; count = 300 * x + 1000; }
    else { i = 1000; count = 300; }
  }

  for (; i <= n; ++i) {
    for (int j = 1; j <= i; j *= 10) {
      if (i / j % 10 == 1) { ++count; }
    }
  }
  printf("%d", count);
  return 0;
}
