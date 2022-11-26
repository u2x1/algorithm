#include <cstdio>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 1e5;
int last;

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    scanf("%d", &last);
    int mx = -1, cur = 1;
    int tmp;
    cfor(i, 1, n, 1) {
      scanf("%d", &tmp);
      if (tmp - last == 1) {
        ++cur;
      } else {
        if (mx < cur) { mx = cur;}
        cur = 1;
      }
      last = tmp;
    }
    printf("%d", mx<cur ? cur : mx); NL;
  }
  return 0;
}
