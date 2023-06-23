#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'
#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, k, q; std::cin >> n >> k >> q;
    std::vector<int> v(n);
    orep(i, 0, n) { std::cin >> v[i]; }
    long long ret = 0;
    orep(i, 0, n) {
      if (v[i] > q) { continue; }
      int cnt = 0;
      for(; i < n && v[i] <= q; ++i) { ++cnt; }
      if (cnt == k) { ret++; }
      else if (cnt > k) { ret += (1 + (cnt-k+1)) * (cnt-k+1) / 2; }
      --i;
    }
    std::cout << ret; NL;
  }

  return 0;
}
