#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 100+5;
int arr[maxN];
const int mod = 998244353;

long long ksm(long long x, long long e) { 
  long long ret = 1;
  while(e) {
    if (e&1) { ret = ret * x % mod; }
    x = x * x % mod; e >>= 1;
  }
  return ret;
}

long long inv(long long x) { return ksm(x, mod-2); }

int dp[maxN][maxN][2];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int N; long long A, B, P, Q; std::cin >> N >> A >> B >> P >> Q;
  const long long ip = inv(P), iq = inv(Q);
  orep(i, 0, N) {
    dp[N][i][0] = dp[N][i][1] = 1;
    dp[i][N][0] = dp[i][N][1] = 0;
  }
  for(int i = N-1; i; --i) {
    for(int j = N-1; j; --j) {
      for(int k = 1; k <= P; ++k) {
        dp[i][j][0] = (dp[i][j][0] + dp[std::min(i+k, N)][j][1]) % mod;
      }
      dp[i][j][0] = dp[i][j][0] * ip % mod;

      for(int k = 1; k <= Q; ++k) {
        dp[i][j][1] = (dp[i][j][1] + dp[i][std::min(j+k, N)][0]) % mod;
      }
      dp[i][j][1] = dp[i][j][1] * iq % mod;
    }
  }
  std::cout << dp[A][B][0];

  return 0;
}
