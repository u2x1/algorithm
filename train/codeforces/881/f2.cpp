#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

struct Info { int sum = 0, mx = 0, mi = 0, premx = 0, premi = 0, sufmx = 0 ,sufmi = 0; };

Info operator+(Info a, Info b) {
  Info ret;
  ret.sum = a.sum + b.sum;
  ret.premx = std::max(a.premx, a.sum + b.premx);
  ret.premi = std::min(a.premi, a.sum + b.premi);
  ret.sufmx = std::max(b.sufmx, a.sufmx + b.sum);
  ret.sufmi = std::min(b.sufmi, a.sufmi + b.sum);
  ret.mx = std::max({a.mx, b.mx, a.sufmx + b.premx});
  ret.mi = std::min({a.mi, b.mi, a.sufmi + b.premi});
  return ret;
}

Info rev(Info a) {
  std::swap(a.premx, a.sufmx);
  std::swap(a.premi, a.sufmi);
  return a;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int q; std::cin >> q;
    std::vector<std::array<int, 3>> qry;
    std::vector<std::vector<int>> son(q+2);
    std::vector<int> dep(q+2);
    std::vector<std::array<int, 26>> fa(q+2);
    std::vector<std::array<Info, 26>> info(q+2);

    dep[1] = 1;
    info[1][0].sum = 1; info[1][0].mx = 1; 
    info[1][0].premx = 1; info[1][0].sufmx = 1; 

    int o = 2;

    orep(_, 0, q) {
      std::string s; std::cin >> s;
      if (s == "+") {
        int u, x;
        std::cin >> u >> x;
        son[u].emplace_back(o);
        fa[o][0] = u; dep[o] = dep[u]+1;
        auto &xx = info[o][0]; xx.sum = x;
        if (x == 1) {
          xx.mx = xx.premx = xx.sufmx = 1;
        } else {
          xx.mi = xx.premi = xx.sufmi = -1;
        }
        for(int k = 1; (1 << k) <= dep[o]; ++k) {
          fa[o][k] = fa[fa[o][k-1]][k-1];
          info[o][k] = info[o][k-1] + info[fa[o][k-1]][k-1];
        }
        ++o;
      } else {
        int a, b, c; std::cin >> a >> b >> c;
        qry.push_back({a, b, c});
      }
    }
    
    auto get = [&](int u, int v) {
      if (dep[u] < dep[v]) { std::swap(u, v); }
      Info l, r;
      for(int k = 25; ~k; --k) {
        if (dep[u]-(1<<k) >= dep[v]) {
          l = l + info[u][k]; u = fa[u][k];
        }
      }
      if (u == v) { return l + info[u][0]; }
      for(int k = 25; ~k; --k) {
        if (fa[u][k] == fa[v][k]) { continue; }
        l = l + info[u][k]; u = fa[u][k];
        r = r + info[v][k]; v = fa[v][k];
      }
      return l + info[u][1] + info[v][0] + rev(r);
    };

    for(auto [u, v, k] : qry) {
      auto x = get(u, v);
//       std::cout << x.mi << " " << x.mx; NL;
      std::cout << (x.mi <= k && k <= x.mx ? "YES" : "NO"); NL;
    }
  }

  return 0;
}
