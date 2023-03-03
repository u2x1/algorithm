#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define NL          std::cout << '\n';

const int maxN = 3e5+5;
int dp[maxN];
std::vector<int> son[maxN];
int ret;

void init(const int u, const int fa) {
  orep(it, son[u].cbegin(), son[u].cend()) {
    const int v = *it;
    if (fa == v) { continue; }
    init(v, u);
  }
  dp[u] = 1;
  orep(i, 0ul, son[u].size()) {
    const int v = son[u][i];
    dp[u] = max(dp[u], 1 + dp[v] + son[u].size()-1-(fa!=-1));
    orep(j, 0ul, i) {
      const int vv = son[u][j];
      ret = max(ret, 1 + dp[v]+dp[vv] + (son[u].size()-2));
    }
  }
  ret = max(ret, dp[u] + (fa!=-1));
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    son[a].push_back(b); son[b].push_back(a);
  }

  init(1, -1); std::cout << ret;

  return 0;
}
