#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, t; std::cin >> n >> t;
  std::vector son(n+5, std::vector<int>());
  std::vector<long long> dis(n+5), v(n+5);
  orep(i, 1, n) { int x; std::cin >> x; son[x-1].push_back(i); }
  orep(i, 1, n) { std::cin >> dis[i]; }
  orep(i, 0, n) { std::cin >> v[i]; ++v[i]; }
  std::vector<long long> dp(n+5);
  std::pair<long long, long long> ret = {-1, 0};
  std::function<std::map<long long, long long>(int)> dfs = [&](int u) {
    dp[u] = v[u];
    std::map<long long, long long> mp;
    mp[-dis[u]] = v[u];
    for(auto x : son[u]) {
      dis[x] += dis[u];
      std::map<long long, long long> tmp = dfs(x);
      if (tmp.size() > mp.size()) { std::swap(tmp, mp); } // the **MAGIC**
      for(auto [a, b] : tmp) { mp[a] += b; }
      dp[u] += dp[x];
    }
    for(auto it = mp.begin(); it != mp.end(); ) {
      auto [d, x] = *it; 
      if (-d-dis[u] > t) { it = mp.erase(it); dp[u] -= x; }
      else { break; }
    }
    ret = std::max(ret, {dp[u], u});
    return mp;
  };
  dfs(0);
  std::cout << ret.second+1 << " " << ret.first;

  return 0;
}
