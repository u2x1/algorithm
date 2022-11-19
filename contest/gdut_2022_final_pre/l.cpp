#include <cstdio>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 1e5;

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    while(n != 1) {
      if (n&1) {
        printf("%d*3+1=%d", n, n*3+1);
        n = n*3+1;
      } else {
        printf("%d/2=%d", n, n/2);
        n /= 2;
      }
      NL;
    }
    if(t) { NL; }
  }
  return 0;
}
