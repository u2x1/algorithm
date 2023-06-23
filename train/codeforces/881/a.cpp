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
    std::sort(all(v));
    long long ret = 0;
    for(int i = 0, j = v.size()-1; i < j; ++i, --j) {
      ret += v[j]-v[i];
    }
    std::cout << ret; NL;
  }

  return 0;
}
