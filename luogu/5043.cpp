#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using ui64 = unsigned long long;

const ui64 mask = std::chrono::steady_clock::now().time_since_epoch().count();
ui64 shift(ui64 x) {
  x ^= mask;
  x ^= x << 13; x ^= x >> 7; x ^= x << 17;
  x ^= mask;
  return x;
};


signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::map<ui64, int> mp;
  std::vector<int> ret(n+1);
  orep(u, 1, n+1) {
    ret[u] = u;
    int k; std::cin >> k;
    std::vector<std::vector<int>> son(k+1);
    orep(i, 1, k+1) {
      int fa; std::cin >> fa;
      if (!fa) { continue; }
      son[fa].emplace_back(i); son[i].emplace_back(fa);
    }
    std::vector<ui64> hs(k+1);
    std::function<void(int, int)> dfs1 = [&](int x, int fa) {
      hs[x] = 1;
      for(auto y : son[x]) {
        if (y == fa) { continue; }
        dfs1(y, x);
        hs[x] += shift(hs[y]);
      }
    };
    std::function<void(int, int)> dfs2 = [&](int x, int fa) {
      if(fa) { hs[x] += shift(hs[fa] - shift(hs[x])); }
      for(auto y : son[x]) {
        if (y == fa) { continue; }
        dfs2(y, x);
      }
    };
    dfs1(1, 0); dfs2(1, 0);
    // NL; NL;
    // std::cout << u; NL;
    // for(auto [a, b] : mp) { std::cout << a << " " << b; NL; }
    ui64 h = 0;
    orep(i, 1, k+1) {
      h += shift(hs[i]);
    }
      // std::cout << "[" << i << "]: " << hs[i]; NL;
    if (mp.count(h)) { mp[h] = std::min(u, mp[h]); }
    else { mp[h] = u; }
    ret[u] = std::min(ret[u], mp[h]);
  }
  orep(i, 1, n+1) { std::cout << ret[i]; NL; }

  return 0;
}
