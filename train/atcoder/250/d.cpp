#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n; std::cin >> n;
  std::vector<long long> primes, vis(1e6);
  orep(i, 2, 1e6) {
    if(!vis[i]) { primes.emplace_back(i); }
    for(auto x : primes) {
      if (i*x >= 1e6) { break; }
      vis[i*x] = 1;
      if (i%x == 0) { break; }
    }
  }
  int l = 0;
  int ret = 0;
  for(int i = primes.size()-1; i > 0; --i) {
    long long x = primes[i] * primes[i] * primes[i];
    if (2 * x > n) { continue; }
    while(l < i && primes[l] * x <= n) { ++l; } --l;
    ret += l+1;
  }
  std::cout << ret;

  return 0;
}
