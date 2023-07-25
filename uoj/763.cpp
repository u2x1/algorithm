#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using ui64 = unsigned long long;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::vector<int>> son(n);
  orep(i, 1, n) {
    int a, b; std::cin >> a >> b;
    --a; --b;
    son[a].emplace_back(b);
    son[b].emplace_back(a);
  }
  const ui64 mask = std::chrono::steady_clock::now().time_since_epoch().count();
  auto shift = [mask](ui64 x) { 
    x ^= mask;
    x ^= x << 13; x ^= x << 7; x ^= x << 17;
    x ^= mask;
    return x;
  };
  std::vector<ui64> hash(n);
  std::set<ui64> ret;
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    hash[u] = 1;
    for(auto x : son[u]) {
      if (x == fa) { continue; }
      dfs(x, u);
      hash[u] += shift(hash[x]);
    }
    ret.emplace(hash[u]);
  };
  dfs(0, -1);
  std::cout << ret.size();

  return 0;
}
