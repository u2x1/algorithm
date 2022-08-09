#include <cstdio>
#include <cstring>

#define orep(i, a, b) for (int i = (a); i <  (b); ++i)
#define crep(i, a, b) for (int i = (a); i <= (b); ++i)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min3(a, b, c) min(min(a,b),c)
#define max3(a, b, c) max(max(a,b),c)
#define printArr(arr,len,type,split) orep(i,0,len) { printf("%" type, arr[i]); putchar(split); }
#define HIT printf("<%s> at ln%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PT(var, d) printf(#var": %" d " ", var);
#define NL putchar(10)

int main() {
  int n;
  scanf("%d", &n);
  int arr[n+1][n+1]={};
  int dp[n+1][n+1]={};
  int row, col, num;
  while(1) {
    scanf("%d%d%d", &row, &col, &num);
    if (!row && !col && !num) { break; }
    arr[row][col] = num;
    dp[row][col] = num;

  }
  crep(i, 1, n) {
    crep(j, 1, n) {
      dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
    }
  }
  int ret = dp[n][n];
  int ii = n, jj = n;
  while(ii != 1 && jj != 1) {
    arr[ii][jj] = 0;
    const int nextii = max(1, ii-1), nextjj = max(1, jj-1);
    if (dp[nextii][jj] > dp[ii][nextjj] && ii != nextii) {
      ii = nextii;
    } else { jj = nextjj; }
  } arr[1][1] = 0;

  crep(i, 1, n) {
    crep(j, 1, n) {
      arr[i][j] += max(arr[i-1][j], arr[i][j-1]);
    }
  }
  ret += arr[n][n];
  printf("%d", ret);

  return 0;
}
