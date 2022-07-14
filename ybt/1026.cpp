#include <cstdio>

int main() {
  char a; int b; float c; double d;
  scanf("%c%d%f%lf", &a, &b, &c, &d);
  printf("%c %d %.6f %.6f", a, b, c, d);
  return 0;
}
