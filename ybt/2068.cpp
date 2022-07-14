#include <cstdio>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int rabbit = (b-2*a)/2;
  printf("%d %d", a-rabbit, rabbit);
  return 0;
}
