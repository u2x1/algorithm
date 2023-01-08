#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define REDIR        freopen("data.in", "r", stdin);

int main() {
  int n, m; scanf("%d%d", &n, &m);
  long long dp[m*2+1]={};
  int arr[n+1]; scanf("%d", arr+1);
  long long rst = 0;
  crep(i, 2, n) {
    scanf("%d", arr+i);
    const int l = arr[i-1], r = arr[i]<l ? arr[i]+m : arr[i];
    rst += r-l;
    if (r > l+1) {
      dp[l+2] += 1;
      dp[r+1] -= r-l;
      dp[r+2] += r-l-1;
    }
  }
  crep(i, 1, m*2) { dp[i] += dp[i-1]; }
  crep(i, 1, m*2) { dp[i] += dp[i-1]; }

  long long diff = -1;
  crep(i, 1, m) { 
    diff=std::max(diff, dp[i]+dp[i+m]);
  }

  printf("%lld", rst - diff);

  return 0;
}
