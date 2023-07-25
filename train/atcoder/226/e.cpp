#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  const int mod = 998244353;
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> son(n+1);
  orep(i, 0, m) {
    int a, b;
    std::cin >> a >> b;
    son[a].push_back(b);
    son[b].push_back(a);
  }
  std::vector<int> visv(n+1);
  int vs = 0, es = 0;
   std::function<void(int)> dfs = [&](const int u) {
    if (visv[u]) { return; }
    vs++; visv[u] = 1;
    es += son[u].size();
    for(auto v : son[u]) { dfs(v); }
  };

  long long ret = 1;
  orep(i, 1, n+1) {
    vs = 0, es = 0;
    dfs(i);
    if (!vs) { continue; }
    if (vs*2 == es) {
      ret = ret * 2ll % mod;
    } else {
      std::cout << 0; return 0;
    }
  }

  std::cout << ret;
  
  return 0;
}
