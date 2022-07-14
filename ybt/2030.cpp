#include <cstdio>
#include <cmath>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  for (int i = a; i <= b; ++i) {
    int boundary = sqrt(i);
    bool flag = 1;
    for (int j = 2; j <= boundary; ++j) {
      if (!(i % j)) { flag = 0; break; }
    }
    if (flag) { printf("%d\n", i); }
  }
  return 0;
}
