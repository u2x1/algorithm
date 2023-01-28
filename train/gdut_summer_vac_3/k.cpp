#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e2+5;
int dp[maxN][maxN];
int cnt[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, m) {
    int win, lose; std::cin >> win >> lose;
    dp[win][lose] = 1;
  }
  orep(k, 1, n+1) {
    orep(i, 1, n+1) {
      orep(j, 1, n+1) {
        dp[i][j] |= (dp[i][k] && dp[k][j]);
      }
    }
  }
  orep(i, 1, n+1) {
    orep(j, 1, n+1) {
      if (dp[i][j]) { cnt[i]++; cnt[j]++; }
    }
  }
  int ret = 0;
  orep(i, 1, n+1) {
    if (cnt[i] == n-1) { ret++; }
  }
  std::cout << ret;

  return 0;
}
