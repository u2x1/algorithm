#include <cstdio>

int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  int dp[t+1]={1}, tmp;
  while(n--) {
    scanf("%d", &tmp);
    for(int j=t; j>=tmp; --j) {
        dp[j] += dp[j-tmp];
    }
  }
  for(int j=1; j<=t; ++j) {
    printf("%d ", dp[j]);
  }
  printf("\n%d", dp[t]);
  return 0;
}
