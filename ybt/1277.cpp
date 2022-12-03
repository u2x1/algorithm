#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)
#define NL           putchar(10);

int arr[100][100], dp[100][100];

int main() {
  int n; scanf("%d", &n);
  int row, col, num;
  while(1) {
    scanf("%d%d%d", &row, &col, &num);
    if (!row && !col && !num) { break; }
    arr[row][col] = num;
  }

  orep(i, 1, n+1) {
    for(int b = 1; b <= n; ++b) {
      for(int a = 1; a <= b; ++a) {
        dp[a][b] += arr[i][a] + (a!=b ? arr[i][b] : 0);
      }
      for(int a = 1; a < b; ++a) {
        dp[a][b] = std::max(dp[a-1][b] + arr[i][a], dp[a][b]);
      }
      for(int a = 1; a < b; ++a) {
        dp[a][b] = std::max(dp[a][b-1] + arr[i][b], dp[a][b]);
      }
      dp[b][b] = std::max(dp[b][b], dp[b-1][b]);
    }
  }
  printf("%d", dp[n][n]);
  return 0;
}
