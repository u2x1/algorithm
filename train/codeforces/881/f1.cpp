#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int q; std::cin >> q;
    std::vector<int> l(q+2), r(q+2);
    std::vector<int> dpl(q+2), dpr(q+2);
    int cnt = 2;
    l[1] = 0; r[1] = 1;
    dpl[1] = 1, dpr[1] = 1;
    orep(_, 0, q) {
      std::string e; std::cin >> e;
      if (e == "+") {
        int v, x; std::cin >> v >> x;
        dpl[cnt] = std::min(dpl[v]+x, x);
        dpr[cnt] = std::max(dpr[v]+x, x);
        l[cnt] = std::min(l[v], dpl[cnt]);
        r[cnt] = std::max(r[v], dpr[cnt]);
        ++cnt;
      } else {
        int u, v, k; std::cin >> u >> v >> k;
        // std::cout << u << " " << v; NL;
        // std::cout << l[v] << " " << r[v]; NL;
        if (l[v] <= k && r[v] >= k) { std::cout << "YES"; NL;}
        else { std::cout << "NO"; NL;}
      }
    }
  }

  return 0;
}
