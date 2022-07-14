#include <cstdio>

int main() {
  int n;
  int a = 0, b = 1;
  scanf("%d", &n);
  int buffer;
  for (int i = 1; i < n; ++i) {
    buffer = a + b;
    a = b;
    b = buffer;
  }
  printf("%d", b);
  return 0;
}
