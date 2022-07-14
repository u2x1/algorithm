#include <cstdio>

int main() {
  int n, cache;
  scanf("%d", &n);
  while (n != 1) {
    if (n % 2) {
      cache = n*3+1;
      printf("%d*3+1=%d\n", n, cache);
      n = cache;
    }
    else {
      cache = n/2;
      printf("%d/2=%d\n", n, cache);
      n = cache;
    }
  }
  printf("END");
  return 0;
}
