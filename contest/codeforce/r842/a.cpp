#include <cstdio>

#define NL putchar(10);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int k; scanf("%d", &k);
    printf("%d", k-1);
    NL;
  }
  return 0;
}
