#include <cstdio>

int main() {
  int a, n;
  scanf("%d%d", &a, &n);
  int s = 0, a_2 = a;
  while(n != 0) {
    s += a_2;
    a_2 = a_2*10+a;
    n--;
  }
  putchar(10);
  printf("%d", s);
  return 0;
}
