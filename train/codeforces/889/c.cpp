#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n);

    int idx = 0;
    {
      int mx = 0;
      int o = 0;
      for(auto &x : v) {
        std::cin >> x;
        if (abs(x) > mx) { mx = abs(x); idx = o; }
        ++o;
      }
      if (mx == 0) { std::cout << 0; NL; continue; }
    }

    std::vector<std::pair<int, int>> ret;
    if (v[idx] > 0) {
      std::pair<int, int> mx = { v[idx], idx };
      for(int i = 0; i < n; ++i) {
        if (v[i] >= 0) { continue; }
        ret.emplace_back(i+1, idx+1);
        v[i] += v[idx];
      }
      for(int i = 0; i < n; ++i) {
        ret.emplace_back(i+1, mx.second+1);
        v[i] += mx.first;
        mx = std::max(mx, std::make_pair(v[i], i));
      }
    } else {
      std::pair<int, int> mi = { v[idx], idx };
      for(int i = 0; i < n; ++i) {
        if (v[i] <= 0) { continue; }
        ret.emplace_back(i+1, idx+1);
        v[i] += v[idx];
      }
      for(int i = n-1; i > -1; --i) {
        ret.emplace_back(i+1, mi.second+1);
        v[i] += mi.first;
        mi = std::min(mi, std::make_pair(v[i], i));
      }
    }
    std::cout << ret.size(); NL;
    for(auto [x, y] : ret) {
      std::cout << x << " " << y; NL;
    }
  }
  return 0;
}

