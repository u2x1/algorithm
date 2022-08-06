#include <cstdio>
#include <algorithm>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int dp[m+1]={}, w, v;
  while(n--) {
    scanf("%d%d", &w, &v);
    for(int i = m; i >= w; --i) {
      dp[i] = std::max(dp[i], dp[i-w] + v);
    }
  }

  printf("%d", dp[m]);

  return 0;
}
