#include <cstdio>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%.4f", (double)(a*87+b*85)/(a+b));

  return 0;
}
