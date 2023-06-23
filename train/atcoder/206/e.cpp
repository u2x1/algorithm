#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long l, r; std::cin >> l >> r;
  l = (l == 1 ? 2 : l);
  std::vector<long long> f(r+1);
  long long ans = 0;
  for(long long x = r; x > 1; --x) {
    long long z = (r/x) - (l-1)/x;
    f[x] = z*z;
    for(long long y = 2*x; y <= r; y += x) { f[x] -= f[y]; }
    ans += f[x];
  }

  for(long long x = r; x >= l; --x) {
    long long z = ((r/x)-(l-1)/x);
    ans -= 2*z - 1;
  }

  std::cout << ans;

  return 0;
}

