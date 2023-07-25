#include <bits/stdc++.h>

#define all(x)      x.rbegin(), x.rend()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  // std::vector<std::array<int, 3>> pt;
  std::vector<std::vector<std::pair<int, int>>> v(4);
  std::vector<std::pair<int, int>> pt;
  orep(i, 0, n) {
    int a, b; std::cin >> a >> b;
    pt.emplace_back(a, b);
    v[0].emplace_back(a+b, i);
    v[1].emplace_back(a-b, i);
    v[2].emplace_back(-a+b, i);
    v[3].emplace_back(-a-b, i);
    // pt.push_back({a, b, i});
  }
  // std::vector<std::array<int, 2>> sgn { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
  // for(auto &x : v) { x = pt; }
  orep(i, 0, 4) {
    std::sort(all(v[i]), [](auto a, auto b) { return a.first == b.first ? a.second < b.second : a.first > b.first; });
    // std::sort(all(v[i]), [&](auto a, auto b) {
    //     auto [x1, y1, _] = a; auto [x2, y2, __] = b;
    //     return (sgn[i][0] * x1 + sgn[i][1] * y1) > (sgn[i][0] * x2 + sgn[i][1] * y2);
    //     });
  }


  std::array<int, 4> idx { 0, 0, 0, 0 };
  std::vector<int> dead(n);

  pt.emplace_back(0, 0);
  int u = pt.size()-1;

  int mxid = -1, len = -1;
  int cx = 0, cy = 0;
  int ret = 0;
  orep(_, 0, n) {
    orep(i, 0, 4) {
      // int dis = sgn[3^i][0]*cx+sgn[3^i][1]*cy;
      while(dead[v[i][idx[i]].second]) { ++idx[i]; }
      int id = v[i][idx[i]].second;
      // auto [x1, y1] = pt[u];
      auto [x2, y2] = pt[id];
      int dis = abs(cx-x2) + abs(cy-y2);
      // auto [x, y, id] = v[i][idx[i]];
      // dis += sgn[i][0]*x + sgn[i][1]*y;
      if (dis > len) { mxid = id; len = dis; }
      if (dis == len && mxid > id) { mxid = id; }
    }
    dead[mxid] = 1; ret += len;
    u = mxid;
    cx = pt[mxid].first;
    cy = pt[mxid].second;
    // auto [cx, cy] = pt[mxid];
    // std::cout << "-> (" << cx << "," << cy << ") ";
    // std::cout << "" 
    len = -1;
  }
  std::cout << ret;


  return 0;
}
