#include <cstdio>
#include <algorithm>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 1e5;

int a[maxN];
long long prefix[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n, m; scanf("%d%d", &n, &m);
    cfor(i, 0, n, 1) {
      scanf("%d", a+i);
    }
    prefix[0] = a[0]; cfor(i, 1, n, 1) { prefix[i] = prefix[i-1] + a[i]; }
    int t, l, r;
    cfor(i, 0, m, 1) {
      scanf("%d%d%d", &t, &l, &r);
      --l; --r;
      if (t == 2) {
        printf("%lld", prefix[r]-(l-1==-1 ? 0 : prefix[l-1])); NL;
      }
    }
  }
  return 0;
}
