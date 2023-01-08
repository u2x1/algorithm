#include <cstdio>
#include <algorithm>

#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)

int main() {
  int n;
  scanf("%d", &n); getchar();
  int dp[n+1][3] = {};
  crep(i, 1, n) {
    const bool c = getchar() - '0';
    if (c) {
      dp[i][0] = dp[i-1][0] + 1;
      dp[i][1] = std::min(dp[i-1][0], dp[i-1][1]);
      dp[i][2] = std::min(std::min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + 1;
    } else {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = std::min(dp[i-1][0], dp[i-1][1]) + 1;
      dp[i][2] = std::min(std::min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
    }
  }

  printf("%d", std::min(dp[n][2], dp[n][1]));

  return 0;
}
