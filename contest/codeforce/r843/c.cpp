#include <cstdio>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    unsigned long long n, x; scanf("%llu%llu", &n, &x);
    if (!x) {
      int l = 0; for(unsigned long long nn=n; nn; l++, nn>>=1);
      printf("%llu", 1ull << l);
      NL; continue;
    }
    int zeros = 0;
    unsigned long long x2 = x, n2 = n;
    int hi = -1;
    while(!(x2 & 1ull)) {
      if (n2 & 1ull) { hi = zeros+1; }
      x2 >>= 1; n2 >>= 1; zeros++;
    }
    if (x2 != n2 || hi == zeros) {
      printf("-1");
      NL; continue;
    }

    printf("%llu", (n2<<zeros) + (~hi ? (1ull<<hi): 0));
    NL;

  }

  return 0;
}
