#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  const int maxN = 5e6;
  std::vector<int> notPrime(maxN), primes;
  std::vector<int> lstPF(maxN, 1);
  for (int i = 2; i < maxN; ++i) {
    if (!notPrime[i]) { primes.emplace_back(i); lstPF[i] = i; }
    for(auto x : primes) {
      if (x * i >= maxN) { break; }
      notPrime[x*i] = 1;
      lstPF[x*i] = x;
      if (i % x == 0) { break; }
    }
  }
  std::vector<int> ok;
  std::vector<int> cnt(maxN, 1);
  for (int i = 2; i < maxN; ++i) {
    int x = i, raw = lstPF[x];
    int c = 1;
    while(raw == lstPF[x]) {
      c++;
      x /= lstPF[x];
    }
    cnt[i] = cnt[x] * c;
  }
  long long magic = 45360;
  long long n; std::cin >> n;
  if (n >= 5e6) {
    std::cout << (n+magic-1)/magic*magic; return 0;
  } else {
    for(int x = n; x*100 <= n*101; ++x) {
      if (cnt[x] >= 100) { std::cout << x; return 0; }
    }
  }
  std::cout << -1; NL;

  return 0;
}
