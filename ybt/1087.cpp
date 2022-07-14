#include <cstdio>

int main() {
  int k;
  double sum;
  scanf("%d", &k);
  for (int i = 1; ; ++i) {
    sum += 1.0/i;
    if (sum > k) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}
