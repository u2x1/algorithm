#include <cstdio>

int main() {
  int a,b;
  scanf("%d%d", &a, &b);
  int ret = 1;
  a %= 1000;
  for (int i = 0; i < b; ++i) {
    ret = ret * a % 1000;
  }
  printf("%03d", ret);
  return 0;
}
