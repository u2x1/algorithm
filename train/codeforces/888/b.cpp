#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n); for(auto & x : v) { std::cin >> x; }
    std::vector<int> odd, even;
    orep(i, 0ul, v.size()) {
      const int x = v[i];
      if (x & 1) { odd.emplace_back(i); }
      else { even.emplace_back(i); }
    }
    auto nodd = odd, neven = even;
    std::sort(all(odd), [&](int a, int b) { return v[a] < v[b]; });
    std::sort(all(even), [&](int a, int b) { return v[a] < v[b]; });
    std::vector<int> end(n);
    orep(i, 0ul, odd.size()) { end[nodd[i]] = v[odd[i]]; }
    orep(i, 0ul, even.size()) { end[neven[i]] = v[even[i]]; }
    std::cout << (std::is_sorted(all(end)) ? "YES" : "NO"); NL;
  }
  return 0;
}
