#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::pair<long long, long long>> v;
  orep(i, 0, 2*n) {
    long long a, b;
    std::cin >> a >> b;
    v.emplace_back(a, b);
  }
  std::sort(all(v));
  std::set<std::pair<long long, long long>> ret;
  orep(idxs, 0, 2*n) {
    orep(idxt, 0, 2*n) {
      if (idxs == idxt) { continue; }
      auto wtf = std::vector<int>(2*n); std::iota(all(wtf), 0);
      std::set<int> vis(all(wtf));
      auto [sx, sy] = v[idxs]; auto [tx, ty] = v[idxt];
      vis.erase(idxs); vis.erase(idxt);
      long long dx = tx-sx, dy = ty-sy;
      while(vis.size()) {
        bool flag = 0; int aa, bb;
        for(auto x : vis) {
          if (flag) { break; }
          for(auto y : vis) {
            if (flag) { break; }
            if (x == y) { continue; }
            auto [ax, ay] = v[x]; auto [bx, by] = v[y];
            if (bx-ax == dx && by-ay == dy) { flag = 1; aa = x, bb =y; }
          }
        }
        if (flag) {
          vis.erase(aa), vis.erase(bb);
        } else { break; }
      }
      if (!vis.size()) { ret.emplace(dx, dy); }
    }
  }
  std::cout << ret.size() ; NL;
  for(auto [x, y] : ret) { std::cout << x << " " << y; NL; }

  return 0;
}

