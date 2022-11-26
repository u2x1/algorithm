#include <cstdio>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 1e5;
char tmpa[maxN], tmpb[maxN];

int map['z'];

int main() {
  int t; scanf("%d", &t);
  map['i'] = 4; map['b'] = 1; map['l'] = 8;
  map['d'] = 8; map['c'] = 1; map['f'] = 4;
  while(t--) {
    int n; scanf("%d", &n);
    long long bytes = 0;
    cfor(i, 0, n, 1) {
      scanf("%s%s", tmpa, tmpb);
      bytes += map[tmpa[0]];
      if (tmpa[0] == 'l') { scanf("%s", tmpb); }
    }
    printf("%lld", (bytes / 1024ll) + (bool)(bytes % 1024ll));
    NL;
  }
  return 0;
}
