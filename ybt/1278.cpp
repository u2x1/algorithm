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
  int m, k;
  scanf("%d", &m);
  int arr[m+1];
  crep(i, 1, m) { scanf("%d", arr+i); arr[i] += arr[i-1]; }

  int dp[k+1][m];
  crep(kk, 1, k) {
    orep(ii, k-1, m) {
      dp[kk][ii] = max(dp[kk][ii], dp[kk-1][ii]
    }
  }

  printf("

  return 0;
}
