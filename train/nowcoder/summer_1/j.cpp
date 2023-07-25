#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int mod = 998244353;
using lnt = long long;
lnt ksm(lnt x, lnt e) {
  lnt ret = 1;
  while(e) {
    if (e & 1) { (ret *= x) %= mod; }
    (x *= x) %= mod; e /= 2;
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  lnt a, b; std::cin >> a >> b;
  b += a-1;
  a++; b++;
  lnt inv2R = ksm(2, mod-2);
  lnt inv2 = inv2R;
  long long ret = 1;
  orep(i, 1, 33) {
    lnt L = (1ll << i), R = L*2-1;
    lnt l = std::max(a, L), r = std::min(b, R);
    if (r >= l) {
      // std::cout << l << " " << r; NL;
      (ret *= ksm((1 - inv2), r-l+1)) %= mod;
      // std::cout << ret; NL;
    }
    (inv2 *= inv2R) %= mod;
  }
  std::cout << ret;

  return 0;
}
