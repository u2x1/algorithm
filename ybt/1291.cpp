#include <cstdio>

int main() {
  int n, t;
  scanf("%d%d", &n, &t);

  int dp[t+1]={}, tmp;
  for(int i=0; i<n; ++i) {
    scanf("%d", &tmp);
    ++dp[tmp];
    for(int j=t; j>=tmp; --j) {
      if (dp[j-tmp]) {
        dp[j] += dp[j-tmp];
      }
    }
  }

  printf("%d", dp[t]);

  return 0;
}
