#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<int> v(n);
  for(auto &x : v) { std::cin >> x; }
  std::vector<std::vector<int>> son(n);
  std::vector<long long> sum(n);
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b; --a, --b;
    son[a].emplace_back(b); son[b].emplace_back(a);
    sum[a] += v[b]; sum[b] += v[a];
  }

  std::vector<int> dead(n);
  std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> q;
  orep(i, 0, n) { q.emplace(sum[i], i); }
  long long ret = 0;
  while(q.size()) {
    auto [_, u] = q.top(); q.pop();
    if (dead[u]) { continue; }
    ret = std::max(sum[u], ret); dead[u] = 1;
    for(auto x : son[u]) {
      if (dead[x]) { continue; }
      sum[x] -= v[u];
      q.emplace(sum[x], x);
    }
  }

  std::cout << ret;

  return 0;
}
