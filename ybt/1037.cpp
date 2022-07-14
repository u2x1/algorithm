#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  long rst = 1;
  for (int i = 0; i < n; ++i) { rst *= 2; }
  printf("%ld", rst);
  return 0;
}
