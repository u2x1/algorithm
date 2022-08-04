#include <cstdio>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long dp[m+1] = {};
  int curr;
  for(int i = 0; i < n; ++i) {
    scanf("%d", &curr);
    if (curr > m) { continue; }
    dp[curr] += 1;
    for(int j = curr; j <= m; ++j) {
      if (dp[j-curr]) {
        dp[j] += dp[j-curr];
      }
    }
  }

//  for(int i = 1; i <= m; ++i) {
//    printf("%d ", dp[i]);
//  } putchar(10);
  printf("%lld", dp[m]);

  return 0;
}
