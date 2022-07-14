#include <cstdio>

int main() {
  int k;
  scanf("%d", &k);
  for (int i = 1; k >= i ; i *= 10) {
    printf("%d ", k / i % 10);
  }
  return 0;
}
