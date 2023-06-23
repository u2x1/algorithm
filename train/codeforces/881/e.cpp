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
    int n, m; std::cin >> n >> m;
    std::vector<int> l(m), r(m);
    orep(i, 0, m) { std::cin >> l[i] >> r[i]; }
    int q; std::cin >> q;
    std::vector<int> vv(q);
    for(auto &x : vv) { std::cin >> x; }
    auto check = [&](int x) {
      std::vector<int> v(n+1);
      orep(i, 0, x) { v[vv[i]] = 1; }
      std::vector<int> sum(n+1);
      orep(i, 1, n+1) { sum[i] = sum[i-1] + v[i]; }
      orep(i, 0, m) {
        int ll = l[i], rr = r[i];
        int one = sum[rr]-sum[ll-1];
        if (one > rr-ll+1-one) { return 1; }
      }
      return 0;
    };
    int ll = -1, rr = q+1;
    while(ll < rr-1) {
      int mi = (ll+rr) / 2;
      if (check(mi)) { rr = mi; }
      else { ll = mi; }
    }
    std::cout << (rr == q+1 ? -1 : rr); NL;
  }

  return 0;
}
