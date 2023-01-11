#include <cstdio>
#include <cstring>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 1e3+5;
const int mod = 1e9+7;
char s1[maxN], s2[maxN];
long long dp[maxN][maxN];
long long sum[maxN][maxN];

int main() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s1, s2);
  sum[0][0] = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = m; j > 0; --j) {
      for(int z = 1; z <= k; ++z) {
        dp[j][z] = (s1[i-1] == s2[j-1] ? (dp[j-1][z] + sum[j-1][z-1])%mod : 0);
        sum[j][z] = (sum[j][z] + dp[j][z]) % mod;
      }
    }
  }
  printf("%lld", sum[m][k]);

  return 0;
}
