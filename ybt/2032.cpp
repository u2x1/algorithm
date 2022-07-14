#include <cstdio>

int main() {
  int n, i = 2;
  scanf("%d", &n);
  printf("%d=", n);
  while (n != 1) {
    if (n % i == 0) {
      printf("%d", i);
      n /= i;
      if (n != 1) { printf("*"); }
      continue;
    }
    ++i;
  }
  return 0;
}
