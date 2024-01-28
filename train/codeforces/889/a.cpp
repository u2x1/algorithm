#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n);
    for(auto &x :v) { std::cin >> x; }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
      if (v[i] == i+1) { ++cnt; }
    }
    std::cout << (cnt+1)/2; NL;
  }

  return 0;
}
