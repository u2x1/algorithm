#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  long long curr = 1;
  double e = 2;
  for (int i = 2; i <= n; ++i) {
    curr *= i;
    e += 1.0/curr;
  }
  printf("%.10f", e);
  return 0;
}

