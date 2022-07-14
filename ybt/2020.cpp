#include <cstdio>
#include <cmath>

int main() {
  int m;
  scanf("%d", &m);
  int n = (1+sqrt(1+8*m))/2;
  while (n*n+n <= 2*m) {
    ++n;
  }
  printf("%d", n);
  return 0;
}
