#include <cstdio>
#include <algorithm>

int main() {
  int v, n;
  scanf("%d%d", &v, &n);
  int tmp, dp[v+1]={};
  while(n--) {
    scanf("%d", &tmp);
    for(int i=v; i>=tmp; --i) {
      dp[i] = std::max(dp[i], dp[i-tmp] + tmp);
    }
  }

  printf("%d", v-dp[v]);

  return 0;
}
