#include <iostream>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::map<int, int> mp;
  int n; std::cin >> n;
  orep(i, 0, n) { int x; std::cin >> x; mp[x]++; }
  for(auto [x, y] : mp) {
    if (y > n/2) { std::cout << x; exit(0); }
  }
  std::cout << "No";

  return 0;
}
