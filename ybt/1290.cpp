#include <cstdio>
#include <algorithm>

int main() {
  int t, m;
  scanf("%d%d", &t, &m);
  int dp[t+1]={};
  int w, v;
  for(int i=0; i<m; ++i) {
    scanf("%d%d", &w, &v);
    for(int j=t; j>=w; --j) {
      dp[j] = std::max(dp[j], dp[j-w] + v);
    }
  }
  printf("%d", dp[t]);
  return 0;
}
