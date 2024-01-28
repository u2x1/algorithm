#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    long long x; std::cin >> x;
    int cnt = 1;
    for(int i = 2; i <= x; ++i) {
      if (x % i) { break; }
      ++cnt;
    }
    std::cout << cnt; NL;
  }


  return 0;
}
