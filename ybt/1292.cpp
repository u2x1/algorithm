#include <cstdio>
#include <algorithm>

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  --m;
  int c, r;

  int dp[n+1][m+1] = {};
  while(k--) {
    scanf("%d%d", &c, &r);
    for(int i = n; i >= c; --i) {
      for(int j = m; j >= r; --j) {
        if (dp[i-c][j-r] + 1 > dp[i][j]) {
          dp[i][j] = dp[i-c][j-r] + 1;
        }
      }
    }
  }

  int cost = m; const int rst = dp[n][m];
  for(; cost >= 0 && dp[n][cost] == rst; --cost);
//  ++cost;

  printf("%d %d", rst, m-cost);

  return 0;
}
