#include <cstdio>

int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  int eaten = y / x;
  int rst = n - eaten;
  if (eaten * x != y) { rst -= 1; }
  if (rst < 0) { rst = 0; } 
  printf("%d", rst);
  return 0;
}
