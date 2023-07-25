#include <bits/stdc++.h>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  
  srand(std::chrono::steady_clock::now().time_since_epoch().count());
  using ll = long long;
  std::mt19937_64 rng(std::random_device{}());
  auto uid = [&](ll l,ll r) { return std::uniform_int_distribution<ll>(l,r)(rng); };

  int t = 1;
  // std::cout << t; NL;
  while(t--) {
    // const int maxN = 20;
    // const int m = (1+rand() % 1000);
    // const int n = (1+rand() % 1000);
    int n = 100, m = 10;
    std::cout << n; NL;
    std::vector<std::pair<long long, long long>> v(2*n);
    const long long bd = 1e8;
    auto dx = uid(-bd, bd), dy = uid(-bd, bd);
    orep(i, 0, n) {
      ll l = uid(-bd, bd), r = uid(-bd, bd);
      v[i] = {l, r};
      v[i+n] = {l+dx, r+dy};
    }
    // std::shuffle(v.begin(), v.end(), rng);
    for(auto [x, y] : v) {
      std::cout << x << " " << y; NL;
    }
  }

  return 0;
}
