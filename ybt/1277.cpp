#include <cstdio>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)
#define crep(i,a,b)  for(int i=(a); i<=(b); ++i)
#define abs(a)       ((a)<0?-(a):(a))
#define min(a,b)     ((a)<(b)?(a):(b))
#define min3(a,b,c)  min(min(a,b),c)
#define max(a,b)     ((a)>(b)?(a):(b))
#define max3(a,b,c)  max(max(a,b),c)
#define HIT          printf("entered <%s> at ln:%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);


int main() {
  int n;
  scanf("%d", &n);

  ++n;
  int arr[n][n]={};
  int row, col, num;
  while(1) {
    scanf("%d%d%d", &row, &col, &num);
    if (!row && !col && !num) { break; }
    arr[row][col] = num;
  }
  int dp[n][n][n][n] = {};
  orep(i, 1, n) {
    orep(j, 1, n) {
      orep(k, 1, n) {
        orep(m, 1, n) {
          dp[i][j][k][m] = max(max(dp[i-1][j][k-1][m], dp[i-1][j][k][m-1])
                              ,max(dp[i][j-1][k-1][m], dp[i][j-1][k][m-1])) + arr[i][j];
          if (i!=k && j!=m) { dp[i][j][k][m] += arr[k][m]; }
        }
      }
    }
  }

  --n;
  printf("%d", dp[n][n][n][n]);

  return 0;
}
