#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    int c, k; scanf("%d%d", &c, &k);
    ++c;
    int loc[c]={}, prof[c]={};
    int dp[c]={}, max = 0;
    for(int i=1; i<c && ~scanf("%d", loc+i); ++i);
    for(int i=1; i<c && ~scanf("%d", prof+i); ++i) {
      dp[i] = prof[i];
    }
    for(int i=1; i<c; ++i) {
      for(int j=0; j<=i; ++j) {
        if (loc[i]-loc[j] > k) { dp[i] = std::max(dp[i], dp[j] + prof[i]); }
        max = std::max(dp[i], max);
      }
    }
    printf("%d\n", max);
  }
  return 0;
}
