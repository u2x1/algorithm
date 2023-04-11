#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
const int mod = 998244353;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long a, b,c , d, e, f; std::cin >> a >> b >> c >> d >> e >> f;
  a %= mod;
  b %= mod;
  c %= mod;
  d %= mod;
  e %= mod;
  f %= mod;
  long long ret = a * b % mod * c % mod;
  long long ret2 = d * e % mod * f % mod;
  ret = (ret-ret2) % mod;
  std::cout << ((ret<0) ? ret + mod : ret);


  return 0;
}
