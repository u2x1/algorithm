#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::map<int, int> mp;
    orep(i, 0, n) { int x; std::cin >> x; mp[x]++; }
    std::vector<int> contri(n+1);
    for(auto [x, y] : mp) {
      for(int xx = x; xx <= n; xx += x) {
        contri[xx] += y;
      }
    }
    std::cout << *max_element(all(contri)); NL;
  }

  return 0;
}
