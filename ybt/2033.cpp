#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int curr = 1, sum = 0;
  for (int i = 1; i <= n; ++i) {
    curr = curr * i % 1000000;
    sum += curr;
  }
  printf("%d", sum % 1000000);
  return 0;
}
