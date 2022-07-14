#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int curr = 1, sum = 0;
  for (int i = 1; i <= n; ++i) {
    curr *= i;
    sum += curr;
  }
  printf("%d", sum);
  return 0;
}

