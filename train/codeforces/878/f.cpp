#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
#include <tuple>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int _; std::cin >> _;
  while(_--) {
    int n, m; std::cin >> n >> m;
    int r; std::cin >> r;
    std::set<std::tuple<int, int, int>> st;
    orep(i, 0, r) {
      int a, b, c; std::cin >> a >> b >> c;
      st.emplace(a, b, c);
    }
    std::set<std::tuple<int, int, int>> vis;
    int ret = 1<<30;
    std::function<void(int, int, int)> dfs = [&](int x, int y, int t) {
      if (x > n || y > m || t > x + y + r || vis.count({x, y, t}) || st.count({t, 1, x}) || st.count({t, 2, y})) { return; }
      vis.emplace(x, y, t);
      if (x == n && y == m) { ret = std::min(ret, t); }
      dfs(x+1, y, t+1);
      dfs(x, y+1, t+1);
      dfs(x, y, t+1);
    };
    dfs(0, 0, 0);
    ret = ret == 1<<30 ? -1 : ret;
    std::cout << ret; NL;
    // orep(i, 0, n+1) {
    //   orep(j, 0, m+1) {
    //     int cnt = -1; orep(t, 0, i+j+100) { if(vis.count({i, j, t})) { cnt = t; break; } }
    //     std::cout << cnt << " ";
    //   } NL;
    // }
  }

  return 0;
}
