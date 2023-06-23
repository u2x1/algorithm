#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <vector>

#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::map<int, std::vector<int>> mp;
  for(int i = 0; i < m; ++i) {
    int a, b; std::cin >> a >> b;
    mp[a].push_back(b);
  }
  std::map<int, bool> f;
  f[n] = 1;
  int ret = 1;
  for(auto [_, v] : mp) {
    std::map<int, bool> ff = f;
    for(auto x : v) {
      if (f[x]) { ff[x] = 0; }
      if (x > 0   && f[x-1]) { ff[x] = 1; }
      if (x < 2*n && f[x+1]) { ff[x] = 1; }
      if (ff[x] != f[x]) { ret += ff[x] - f[x]; }
    }
    std::swap(f, ff);
  }
  std::cout << ret;

  return 0;
}
