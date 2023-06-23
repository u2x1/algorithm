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
    int n; std::cin >> n;
    std::vector<int> v(n); for(auto &x : v) { std::cin >> x; }
    long long ret1 = 0, ret2 = 0;
    orep(i, 0, n) {
      if (v[i] >= 0) { ret1 += v[i]; continue; }
      for(; i < n && v[i] <= 0; ++i) { ret1 += -v[i]; } --i;
      ++ret2;
    }
    std::cout << ret1 << " " << ret2; NL;
  }


  return 0;
}
