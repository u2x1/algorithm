#include <iostream>
#include <vector>
#include <algorithm>

#define orep(x, a, b) for(int x = (a); x < (b); ++x)
#define NL            std::cout << '\n'
#define all(x) 	      x.begin(), x.end()

#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int _; std::cin >> _;
  while(_--) {
    int n, m; std::cin >> n >> m;
    int ret = -(1ll<<60);
    int sum = 0, cur = 0;
    orep(i, 0, n) {
      int x, y; std::cin >> x >> y;
      if (!i && x <= 0) { ret = std::max(x, ret); }
      if (x < 0 && cur > 0) {
        int a = std::min(y, (cur/-x));
        ret = std::max(ret, sum + (cur*a) + ((1+a)*a/2)*x);
      }
      sum += (cur*y) + ((1+y)*y/2)*x;
      cur += x*y;
      ret = std::max(ret, sum);
    }
    std::cout << ret; NL;
  }
  return 0;
}
