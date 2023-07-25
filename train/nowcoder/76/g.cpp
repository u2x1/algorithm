#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int mod = 998244353;
long long qsm(long long x, long long e) {
  long long ret = 1ll;
  while(e) {
    if (e&1) { ret = ret * x % mod; }
    x = x * x % mod; e >>= 1;
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    long long x; std::cin >> x;
    if (x == 1) { std::cout << x; NL; continue; }
    long long invx = qsm(x, mod-2);
    long long ts = std::ceil(std::log2(x));
    // std::cout << (x+1)/2 << " " << (x/2); NL;
    long long ret = ((x+1)/2) * ts % mod * invx % mod + (x/2) * (ts+1) % mod * invx % mod;
    std::cout << ret % mod; NL;
  }

  return 0;
}
