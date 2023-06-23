#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int mod = 1e9+7;

int ksm(long long x, int e) {
  long long ret = 1;
  while(e) {
    if (e&1) { ret = ret * x % mod; }
    e >>= 1; x = x * x % mod;
  }
  return ret;
}

int rev(int x) { return ksm(x, mod-2); }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, k; std::cin >> n >> k;
  std::vector<long long> v(n); for(auto &x : v) { std::cin >> x; }
  long long raw = 0;
  orep(i, 0, n) {
    orep(j, 0, i) {
      raw += (v[j] > v[i]);
    }
  }
  long long extra = 0;
  for(auto x : v) {
    for(auto y : v) { 
      extra += (x > y);
    }
  }
  std::cout << (1ll*raw*k%mod+1ll*extra*k%mod*(k-1)%mod*rev(2)%mod) % mod;

  return 0;
}
