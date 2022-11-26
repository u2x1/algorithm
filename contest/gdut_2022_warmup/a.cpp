#include <cstdio>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 1e5;

int main() {
  int t, tmp; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    bool flag = 1;
    while(n--) {
      scanf("%d", &tmp);
      if (flag && tmp == 0) { printf("Transform Mobility With Autonomous Driving"); flag = 0; }
    }
    printf(flag ? "WeRide.ai" : "");
    NL;
  }
  return 0;
}
