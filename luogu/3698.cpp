#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e2+5;
bool vis[maxN]; int dp[maxN];
std::vector<std::vector<int>> son;

void init(int u=0, int color = -1) {
  if (son[u].size() == 0) { dp[u] = 1; return; }
  vis[u] = 1; dp[u] = 0;
  orep(i, 0ul, son[u].size()) {
    const int v = son[u][i];
    if (color == v) { continue; }
    init(v, u);
    dp[u] = std::max(dp[u], dp[v]);
  }
  dp[u]++;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int v, n; std::cin >> v >> n;
  son = std::vector<std::vector<int>>(v+1);
  orep(i, 1, v) {
    int a, b; std::cin >> a >> b;
    son[a].push_back(b);
    son[b].push_back(a);
  }
  init();
  std::cout << (dp[0] > n ? n+1 : std::min(v, dp[0]+(n-dp[0]+1)/2));
  return 0;
}
