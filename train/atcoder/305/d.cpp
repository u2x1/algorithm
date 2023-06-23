#include <iostream>
#include <algorithm>
#include <vector>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q; std::cin >> n;
  n = (n-1) / 2; int _; std::cin >> _;
  std::vector<std::pair<int, int>> v(n);
  for(auto& [x, y] : v) { std::cin >> x >> y; }
  std::sort(v.begin(), v.end());

  std::vector<long long> sum(n+1);
  orep(i, 0, n) { sum[i+1] = sum[i] + v[i].second - v[i].first; }
  std::vector<int> v1, v2;
  for(auto [x, y] : v) { v1.emplace_back(x); v2.emplace_back(y); }

  std::cin >> q;
  while(q--) {
    int L, R; std::cin >> L >> R;
    int l = std::upper_bound(all(v1), L) - v1.begin() - 1;
    int r = std::lower_bound(all(v2), R) - v2.begin();
    if (l == r) { std::cout << R-L; NL; continue; }
    long long ret = 0;
    if (l != -1 && v2[l] >= L) { ret += v2[l] - L; }
    if (r != n && v1[r] <= R) { ret += R - v1[r]; }
    ret += sum[r]-sum[l+1];
    std::cout << ret; NL;
  }


  return 0;
}
