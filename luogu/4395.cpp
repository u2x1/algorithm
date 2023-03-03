#include <iostream>
#include <climits>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e4+5;
long long dp[maxN][15];
std::vector<std::vector<int>> son;

void init(const int u, const int fa) {
  orep(it, son[u].cbegin(), son[u].cend()) {
    const int v = *it;
    if (v == fa) { continue; }
    init(v, u);
  }

  orep(i, 1, 15) {
    dp[u][i] = i;
    orep(it, son[u].cbegin(), son[u].cend()) {
      const int v = *it;
      if (v == fa) { continue; }
      long long mi = 1ll<<62;
      orep(ii, 1, 15) {
        if (i == ii) { continue; }
        mi = std::min(dp[v][ii], mi);
      }
      dp[u][i] += mi;
    }
    // std::cout << fa << " "<< u << " " << i << ": " << dp[u][i]; NL;
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  son = std::vector<std::vector<int>>(n+1);
  orep(i, 1, n) {
    int a, b; std::cin >> a >> b;
    son[a].push_back(b);
    son[b].push_back(a);
  }
  init(1, 0);
  long long ret = 1ll<<62;
  orep(i, 1, 15) {
    ret = std::min(ret, dp[1][i]);
  }
  std::cout << ret;
  return 0;
}
