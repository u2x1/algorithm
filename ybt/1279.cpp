#include <cstdio>
#include <cstring>

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
  int f, v;
  scanf("%d%d", &f, &v);

  int dp[f+1][v+1]={}; memset(dp, -0x3f, sizeof(dp));
  dp[0][0] = 0;
  crep(i, 1, f) { dp[i][0] = 0; }
  crep(i, 1, v) { dp[0][i] = 0; }
  int a[f+1][v+1]={};
  int sl[f+1][v+1]={};
  crep(i, 1, f) {
    crep(j, 1, v) {
      scanf("%d", &a[i][j]);
      crep(ii, 1, j) {
        if (dp[i][j] < dp[i-1][ii-1]+a[i][ii]) {
          dp[i][j] = dp[i-1][ii-1]+a[i][ii];
          sl[i][j] = ii;
        }
      }
    }
  }
  crep(i, 0, f) {
    crep(j, 0, v) {
      printf("%4d ", dp[i][j]);
    } putchar(10);
  }
  printf("%d\n", dp[f][v]);
  int rev[f+1];
  for(int i = f, j = v; i>0; --i) {
    rev[i] = sl[i][j];
    j = sl[i][j]-1;
  }
  crep(i, 1, f) { printf("%d ", rev[i]); }

  return 0;
}
