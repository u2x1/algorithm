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
    long long x; std::cin >> x;
    long long ret = 0;
    while(x) {
      ret += x;
      x /= 2;
    }
    std::cout << ret; NL;
  }

  return 0;
}
