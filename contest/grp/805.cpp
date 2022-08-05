#include <cstdio>

int dp[99999999];

int main() {
  dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 3;
  for(int i = 4; i < 9999; ++i) {
    dp[i] = dp[i-4] + dp[i-1];
  }
  int x;
  while(~scanf("%d", &x) && x != 0) {
    printf("%d\n", dp[x]);
  }
  return 0;
}
