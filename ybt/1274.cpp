#include <cstdio>
#include <algorithm>
#include <cstring>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n+1]={0}, dp[n+1][n+1];
  memset(dp, 0x1f, (n+1)*(n+1)*sizeof(int));
  for(int i=1; i<=n; ++i) {
    scanf("%d", arr+i);
    arr[i] += arr[i-1];
    dp[i][i] = 0;
  }
  for(int i=n; i>0; --i) {
    for(int j=i+1; j<=n; ++j) {
      for(int k=i; k<j; ++k) {
        dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[j] - arr[i-1]);
//        printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
      }
    }
  }

  printf("%d", dp[1][n]);

  return 0;
}
