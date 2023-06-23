#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<int> learn(n+1);
  std::vector<int> mt(m);
  for(auto &x : mt) { std::cin >> x; }
  for(auto x : mt) { learn[x] = 1; }

  std::vector<std::vector<int>> out(n+1);
  std::vector<std::vector<int>> in(n+1);
  orep(i, 1, 1+n) {
    int k; std::cin >> k;
    int tmp;
    orep(_, 0, k) { std::cin >> tmp; out[i].emplace_back(tmp); in[tmp].emplace_back(i); }
  }

  std::vector<int> on(n+1);
  orep(i, 1, n+1) { on[i] = out[i].size(); }

  std::vector<int> wtf;
  std::vector<int> vis(n+1);
  std::function<void(int)> dfs = [&](int v) {
    if (vis[v]) { return; }
    vis[v] = 1;
    wtf.emplace_back(v);
    for(auto x : out[v]) { dfs(x); }
  };

  for(auto v : mt) {
    dfs(v);
  }

  std::queue<int> q;
  std::vector<int> yes(n+1);
  for(auto x : wtf) {
    yes[x] = 1;
    if (on[x] == 0) {
      q.emplace(x);
    }
  }

  std::vector<int> dead(n+1);
  std::vector<int> ret;
  while(q.size()) {
    auto u = q.front(); q.pop();
    ret.emplace_back(u); dead[u] = 1;
    for(auto x : in[u]) {
      if (dead[x]) { continue; }
      --on[x];
      if (on[x] == 0 && yes[x] == 1) {
        q.emplace(x);
      }
    }
  }
  if (ret.size() != wtf.size()) { std::cout << -1; return 0; }
  std::cout << wtf.size(); NL;
  for(auto x : ret) { std::cout << x << " "; }

  return 0;
}
