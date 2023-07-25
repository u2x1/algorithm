#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<__int128> a(n), b(n);
  orep(i, 0, n) { long long x, y; std::cin >> x >> y; a[i] = x; b[i] = y; }
  std::vector<int> ret(n); 
  std::iota(all(ret), 0);
  std::sort(all(ret), [&](auto x, auto y) { return a[x]*(a[y]+b[y]) == a[y]*(a[x]+b[x]) ? x < y : a[x]*(a[y]+b[y]) > a[y]*(a[x]+b[x]); });
  for(auto x : ret) { std::cout << x+1 << " "; }
  return 0;
}
