#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> v(n), p(n), vis(n);
  for(auto &x : v) { std::cin >> x; }
  for(auto &x : p) { std::cin >> x; --x; }
  int ret = 1;
  for(int i = 0; i < n; ++i) {
    if (vis[i]) { continue; }
    std::map<int, std::vector<int>> mp;
    std::vector<std::pair<int, int>> vv;
    int c = 0;
    for(int idx = i; !vis[idx]; idx = p[idx], ++c) {
      mp[v[idx]].push_back(c);
      vv.emplace_back(v[idx], mp[v[idx]].size()-1);
      vis[idx] = 1;
      // std::cout << idx; NL;
    }
    for(auto [x, y] : vv) {
      int a = mp[x].size();
      // std::cout << x << " " << y << " " << mp[x][y] << " " << mp[x][(y-1 + a) % a] << " " << (c + mp[x][y] - mp[x][(y-1 + a) % a]) % c; NL;
      int cur = (mp[x][y] - mp[x][(y-1 + a) % a]);
      cur = cur > 0 ? cur : c+cur;
      ret = std::max(ret, cur);
    }
  }
  std::cout << ret;

  return 0;
}
