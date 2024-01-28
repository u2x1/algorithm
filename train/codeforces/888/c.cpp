#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, k; std::cin >> n >> k;
    std::vector<int> v(n);
    for(auto &x : v) { std::cin >> x; }
    int l = 0, r = n - 1;
    int lcnt = k, rcnt = k;
    for(; l < n; ++l) {
      if (v[l] == v[0]) { --lcnt; }
      if (!lcnt) { break; }
    }
    for(; r > l; --r) {
      if (v[r] == v[n-1]) { --rcnt; }
      if (!rcnt) { break; }
    }
    // std::cout << l << " " << r; NL;
    // std::cout << lcnt << " " << rcnt; NL;
    if (v[0] == v[n-1] && (!lcnt || !rcnt)) { std::cout << "YES"; NL; continue; }
    if (lcnt || rcnt) { std::cout << "NO"; NL; continue; }
    std::cout << "YES"; NL;
  }

  return 0;
}
