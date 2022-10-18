#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int mod = 1e9 + 7;
int dp[1000005];

void cal() {
  dp[0] = 0;
  orep(i, 1, 1000005) {
    dp[i] = (dp[i-1]<<1|1) % mod;
  }
}

int main() {
  int t;
  cal();
  scanf("%d", &t);
  while(t--) {
    int n, x; scanf("%d%d", &n, &x);
    int ls = x-1, rs = n-x;
    printf("%d", (dp[ls]+dp[rs])%mod); NL;
  }

  return 0;
}
