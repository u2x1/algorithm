#include <cstdio>

int main() {
  int n, rst = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    rst = rst * 92 % 100;
  }
  printf("%d", rst);
  return 0;
}
