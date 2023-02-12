#include <iostream>
#include <cmath>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int a[305], b[305], t[305];
long long dp[2][maxN];
int q[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, d; std::cin >> n >> m >> d;
  bool md = 0;
  orep(k, 0, m) {
    std::cin >> a[k] >> b[k] >> t[k];
    md = !md;
    int l = 0, r = 0;
    int j = 0;
    orep(i, 0, n) {
      const long long w = k ? 1ll*d*(t[k]-t[k-1]) : 0;
      for(; j < n && j <= i + w; ++j) {
        while(l!=r && dp[!md][j] > dp[!md][q[r-1]]) { --r; }
        q[r++] = j;
      }
      while(l!=r && q[l] < i - w) { l++; }
      dp[md][i] = dp[!md][q[l]] + b[k] - abs(a[k] - (i+1));
    }
  }
  long long ret = dp[md][0];
  orep(i, 1, n) { ret = std::max(dp[md][i],ret); }
  std::cout << ret;

  return 0;
}
