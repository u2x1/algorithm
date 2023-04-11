#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

struct st { int x, y, m, step; };

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int x, y; std::cin >> x >> y;
    int ret = x+y;
    orep(k, 1, 100000) {
      ret = std::min((x+k-1)/k+(y+k-1)/k+(k-1), ret);
    }
    std::cout << ret; NL;
  }

  return 0;
}
