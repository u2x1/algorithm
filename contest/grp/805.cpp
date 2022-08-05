#include <cstdio>

int main() {
  int dp[9999999] = {1, 1, 2, 3};
  for(int i = 4; i < 9999; ++i) {
    dp[i] = dp[i-4] + dp[i-1];
  }
  int x;
  while(~scanf("%d", &x)) {
    printf("%d\n", dp[x]);
  }

  return 0;
}
