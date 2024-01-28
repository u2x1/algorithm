#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<int> v(n);
  for(auto &x : v) { std::cin >> x; }
  for(int i = 0; i < m; ++i) {
      int a, b; std::cin >> a >> b;
      --a; --b;
      int ret = 0;
      for(int x = a; x <= b; ++x) {
          for(int y = x+1; y <= b; ++y) {
              for(int z = y+1; z <= b; ++z) {
                  if (v[x] == v[z] && v[x] > v[y]) {
                      ++ret;
                  }
              }
          }
      }
      std::cout << ret; NL;
  }
  return 0;
}

