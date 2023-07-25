#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, m; std::cin >> n >> m;
    std::vector<int> deg(n);
    orep(i, 0, m) {
      int a, b; std::cin >> a >> b;
      a--; b--;
      deg[a]++; deg[b]++;
    }
    std::map<int, int> mp;
    for(auto y : deg) { mp[y]++; }
    if (mp.size() == 2) {
      int a, b;
      for(auto [x, y] : mp) {
        if (x == 1) { a = y; }
        else { b = y; }
      }
      std::cout << (b-1) << " " << a/(b-1); NL;
    } else {
      int a;
      for(auto [x, y] : mp) {
        if (y == 1) { continue; }
        if (x == 1) { a = y; }
      }
      std::cout << (n-1-a) << " " << a/(n-1-a); NL;
    }
  }

  return 0;
}
