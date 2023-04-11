#include <iostream>
#include <cstring>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 5e3+5;
const int mod = 1e9+7;
int arr[maxN];
int dp[maxN];
int len[maxN];
int cnt[maxN][maxN];
int c[maxN][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  c[0][0] = 1;
  orep(i, 1, maxN) {
    c[i][0] = 1;
    orep(j, 1, maxN) {
      c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    }
  }

  while(t--) {
    int n, k; std::cin >> n >> k;
    // memset(cnt, 0, sizeof(cnt));
    orep(i, 1, n+1) {
      std::cin >> arr[i];
      dp[i] = 0; len[i] = 0;
      orep(x, 1, n+1) { cnt[i][x] = cnt[i-1][x]; }
      ++cnt[i][arr[i]];
      if (cnt[i][arr[i]] >= k) {
        len[i] = 1;
        dp[i] = c[cnt[i][arr[i]]-1][k-1];
      }
    }
    int maxlen = 0; long long ret = 1;
    orep(i, 1, n+1) {
      orep(j, 1, i) {
        int ct = cnt[i][arr[i]] - cnt[j][arr[i]];
        if (len[j] && ct >= k && len[j] >= len[i]-1) {
          if (len[j]+1 > len[i]) { dp[i] = 0; len[i] = len[j] + 1; }
          dp[i] = (dp[i] + 1ll * dp[j] * c[ct-1][k-1] % mod) % mod;
          // std::cout << "dp " << i << " updated at " << i << " " << j << " to " << dp[i] << " with len " << len[i]; NL;
        }
      }
      if (len[i] > maxlen) { ret = 0; maxlen = len[i]; }
      if (len[i] == maxlen) { ret = (ret+dp[i])%mod; }
    }
    std::cout << ret; NL;
  }

  return 0;
}
