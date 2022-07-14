#include <cstdio>

int main() {
  int m, k;
  scanf("%d%d", &m, &k);
  if (m % 19 == 0) {
    int count = 0;
    for (int i = 1; m >= i; i *= 10) {
      if (m / i % 10 == 3) { ++count; }
    }
    if (count == k) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
  return 0;
}
