#include <cstdio>

int main() {
  int n, buffer;
  long sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n && scanf("%d", &buffer); ++i) {
    sum += buffer;
  }
  printf("%ld %.5f", sum, 1.0 * sum / n);
  return 0;
}
