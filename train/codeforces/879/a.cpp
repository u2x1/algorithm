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
    int a = 0, b = 0;
    orep(i, 0, n) { int tmp; std::cin >> tmp; if (tmp == 1) { ++a; } else { ++b; } }
    int c = 0;
    while(b&1 || a < b) {
      ++a; --b;
      ++c;
    }
    std::cout << c; NL;
  }

  return 0;
}
