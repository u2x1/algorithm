#include <cstdio>
#include <numeric>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define NL           putchar(10);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    long long n; scanf("%lld", &n);
    printf("%lld", n*(n-1)*(n-2)/(1*2*3)); NL;
    // why? C(n, 3).
  }
  return 0;
}
