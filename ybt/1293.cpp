#include <cstdio>

int main() {
  int books[4] = {10, 20, 50, 100};
  int n;
  scanf("%d", &n);
  if (!n) { printf("0"); return 0; }
  int dp[n+1] = {1};
  for(int i=0; i<4; ++i) {
    for(int j=books[i]; j <= n; ++j) {
      dp[j] += dp[j-books[i]];
    }
  }

  printf("%d", dp[n]);

  return 0;
}
