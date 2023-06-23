#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int mod = 1e9+7;

long long ksm(long long x, int e) {
  long long ret = 1;
  while(e) {
    if (e&1) { ret = (ret * x) % mod; }
    e >>= 1; x = x * x % mod;
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  std::vector<long long> f(k+1);
  long long ret = 0;
  for(int x = k; x; --x) {
    f[x] = ksm(k/x, n) % mod;
    for(int y = x*2; y <= k; y += x) {
      f[x] = (f[x] - f[y] + mod) % mod;
    }
    ret = (f[x]*x%mod + ret) % mod;
  }
  std::cout << ret;

  return 0;
}
