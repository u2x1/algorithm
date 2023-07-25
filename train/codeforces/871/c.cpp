#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    const int inf = 0x3f3f3f3f;
    std::vector<int> v(20, inf);
    orep(i, 0, n) {
      int x, y; std::cin >> x >> y;
      v[y] = std::min(v[y], x);
    }
    int ret = std::min(v[11], v[1]+v[10]);
    std::cout << (ret == inf ? -1 : ret) ; NL;
  }

  return 0;
}
