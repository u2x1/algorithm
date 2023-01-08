#include <cstdio>
#include <vector>

#define NL putchar(10);


const int maxN = 2e5;

long long prefix[maxN];

int main() {
  int n, q; scanf("%d%d", &n, &q);
  int tmp;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &tmp);
    prefix[i] = prefix[i-1] + tmp;
  }

  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld", prefix[b] - prefix[a-1]);
    NL;
  }

  return 0;
}
