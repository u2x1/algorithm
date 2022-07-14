#include <cstdio>

int main() {
  int m;
  double sum = 0;
  scanf("%d", &m);
  for (int i = 1; sum < m; ++i) {
    sum += 1.0/i;
    if (sum >= m) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}
