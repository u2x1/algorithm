#include <cstdio>

int main() {
  int i, r;
  scanf("%d%d", &i, &r);
  int count = 0;
  for (; i <= r; ++i) {
    for (int j = 1; j <= i; j *= 10) {
      if (i / j % 10 == 2) { ++count; }
    }
  }
  printf("%d", count);
  return 0;
}
