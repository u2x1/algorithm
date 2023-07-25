#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  using ll = long long;

  std::mt19937_64 rng(std::random_device{}());
  auto uid = [&](ll l,ll r) { return std::uniform_int_distribution<ll>(l,r)(rng); };

  const int maxN = 1e4;
  const int bd = 1e8;
  std::set<int> s;
  orep(i, 0, maxN) {
    s.emplace(uid(-bd, bd));
  }

  std::set<int> ret;
  for(auto x : s) {
    for(auto y : s) {
      ret.emplace(y-x);
    }
  }
  std::cout << ret.size();

  return 0;
}
