#include <iostream>
#include <cstring>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int vis[10];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  int must = 0;
  for(auto x : s) { must += (x == 'o'); }
  int ret = 0;
  orep(_x, 0, 10000) {
    int x = _x;
    int m = 0;
    bool no = 0;
    memset(vis, 0, sizeof vis);
    orep(i, 0, 4) {
      int a = x % 10;
      x /= 10;
      if (vis[a]) { continue; }
      else {
        if (s[a] == 'o') { ++m; }
        else if (s[a] == 'x') { no = 1; break; }
        vis[a] = 1;
      }
    }
    if (!no && must == m) { ++ret; }
  }
  std::cout << ret;

  return 0;
}
