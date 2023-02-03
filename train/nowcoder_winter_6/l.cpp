#include <iostream>
#include <vector>
#include <set>
#include <bitset>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int mod = 1e9+7;
const int maxN = 2e5+5;
int dp[2][maxN];
bool hasx[maxN], hasy[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;

  std::set<std::pair<int, int>> no;

  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    no.insert({a, b});
    hasx[a] = 1; hasy[b] = 1;
  }

  dp[0][1] = 1;
  bool mode = 1;
  long long ret = 0;
  for(int i = n; i > 0; --i) {
    for(int j = 1; j <= i; ++j) {
      if (hasx[n-i+1] && hasy[j] && no.find(std::make_pair(n-i+1, j)) != no.end()) { dp[mode][j] = 0; continue; }
      dp[mode][j] = (dp[!mode][j] + dp[mode][j-1]) % mod;
      // std::cout << dp[mode][j] << " ";
    }
    ret = (ret + dp[mode][i]) % mod;
    mode = !mode;
  }

  std::cout << ret;

  return 0;
}
