#include <bits/stdc++.h>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  
  // srand(std::chrono::steady_clock::now().time_since_epoch().count());
  using ll = long long;
  std::mt19937_64 rng(std::random_device{}());
  auto uid = [&](ll l,ll r) { return std::uniform_int_distribution<ll>(l,r)(rng); };

  int t = 1;
  // std::cout << t; NL;
  while(t--) {
    // int n = 5e1, m = 1;
    int a = uid(-10, 10);
    int b = uid(a+1000000, a+3000000);
    int c = uid(b+1000000, b+3000000);
    int aa = uid(0, 5);
    int bb = uid(0, 5);
    int cc = uid(1, 5);
    std::cout << a << " " << aa; NL;
    std::cout << b << " " << bb; NL;
    std::cout << c << " " << cc; NL;
    int n = uid(1, aa + bb + cc);
    std::cout << n; NL;
    std::vector<int> v(n);
    for(auto &x : v) { x = uid(-10, 10); std::cout << x << " "; } NL;
    // std::iota(v.begin(), v.end(), 2);
    // for(auto &x : v) { x = uid(1, sqrt(n)); std::cout << x << " "; } NL;
    // n = sqrt(n) + 1;
    // for(int i = 0; i < m; ++i) {
    //   int l = uid(1, n), r = uid(l, n);
    //   // int l = 1, r = n;
    //   std::cout << l << " " << r; NL;
    // }
  }

  return 0;
}
