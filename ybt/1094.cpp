#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 7 == 0) { continue; }
    bool flag = 0;
    for (int j = 1; j <= n; j *= 10) {
      if (i / j % 10 == 7) { flag = 1; break; }
    }
    if (flag) { continue; }
    sum += i*i;
  }
  printf("%d", sum);
  return 0;
}
