#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  const int mod = 998244353;
  while(t--) {
    int n; std::cin >> n;
    long long cur = 0;
    bool zero = 1; bool one = 0;
    orep(i, 0, n) {
      int x; std::cin >> x;
      if (!x) { continue; }
      if (zero) {
        if (x == 1) { one = 1; }
        cur += x;
        zero = 0;
      } else if (one) {
        cur += x;
        one = 0;
      } else if(x == 1) {
        cur += x;
      } else {
        cur *= x;
      }
      cur %= mod;
    }
    std::cout << cur; NL;
  }

  return 0;
}
