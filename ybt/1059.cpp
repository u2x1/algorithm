#include <cstdio>

int main() {
  int n, ages;
  scanf("%d", &n);
  int cache;
  for (int i = 0; i < n && scanf("%d", &cache); ++i) {
    ages += cache;
  }
  printf("%.2f", (double)ages/n);
  return 0;
}
