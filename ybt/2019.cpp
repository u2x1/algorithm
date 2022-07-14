#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  long rst = 1;
  for (int i = 1; i <= n; ++i) {
    rst *= i;
  }
  printf("%ld", rst);
  return 0;
}
