#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using ui64 = unsigned long long;

const ui64 mask = std::chrono::steady_clock::now().time_since_epoch().count();
ui64 shift(ui64 x) {
  x ^= mask;
  x ^= x << 13; x ^= x >> 7;
 //  x ^= x << 17;
  x ^= mask;
  return x;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;

  std::vector adj(2, std::vector(n+2, std::vector<int>()));
  orep(i, 1, n) {
    int a, b; std::cin >> a >> b;
    adj[0][a].push_back(b); adj[0][b].push_back(a);
  }

  orep(i, 0, n) {
    int a, b; std::cin >> a >> b;
    adj[1][a].push_back(b); adj[1][b].push_back(a);
  }
  
  std::vector hs(2, std::vector<ui64>(n+2, 0ull));
  std::function<void(int, int, int)> dfs1 = [&](int o, int x, int fa) {
    hs[o][x] = 1;
    for(auto y : adj[o][x]) {
      if (y == fa) { continue; }
      dfs1(o, y, x); hs[o][x] += shift(hs[o][y]);
    }
  };

  std::function<void(int, int, int)> dfs2 = [&](int o, int x, int fa) {
    // std::cout << hs1[x] << " -> " << hs1[x] + (!fa ? 0 : shift(hs1[fa] - shift(hs1[x]))); NL; 
    // std::cout << x << " added " << fa << ": " << (!fa ? 0 : shift(hs1[fa] - shift(hs1[x]))); NL;
    // NL;
    if (fa) { hs[o][x] += shift(hs[o][fa] - shift(hs[o][x])); }
    for(auto y : adj[o][x]) {
      if (y == fa) { continue; }
      dfs2(o, y, x);
    }
  };

  dfs1(0, 1, 0); dfs2(0, 1, 0);
  dfs1(1, 1, 0); dfs2(1, 1, 0);

  std::set<ui64> st;
  // orep(i, 1, n+1) { st.emplace((hs1[i])); }
  orep(i, 1, n+1) { st.emplace(shift(hs[0][i])); }
  // ui64 h1 = std::accumulate(hs1.begin()+1, hs1.end(), 0ull);
  // ui64 h2 = std::accumulate(hs2.begin()+1, hs2.end(), 0ull);
  // ui64 h1 = 0, h2 = 0;
  // orep(i, 1, n+1) { h1 += shift(hs1[i]); }
  // orep(i, 1, n+2) { h2 += shift(hs2[i]); }

  // std::cout << h1 << " " << h2; NL;
  
  // orep(i, 1, n+1) { 
  //   std::cout << i << ": ";
  //   std::cout << hs1[i]; NL;
  // } NL;

  orep(i, 1, n+2) {
    // std::cout << i << ": ";
    // std::cout << hs2[i]; NL;
    if (adj[1][i].size() != 1) { continue; }
    if (st.count(hs[1][i]-1)) { std::cout << i; return 0; }
  }
  return 0;
}
