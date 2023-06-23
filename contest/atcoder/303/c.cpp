#include <iostream>
#include <map>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
std::map<int, std::map<int, bool>> mp;


signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, h, k; std::cin >> n >> m >> h >> k;
  std::string s; std::cin >> s;
  orep(i, 0, m) {
    int x, y; std::cin >> x >> y;
    mp[x][y] = 1;
  }
  int x = 0, y = 0;
  for(auto c : s) {
    int dx = 0, dy = 0;
    if (c == 'R') { dx = 1; }
    if (c == 'L') { dx = -1; }
    if (c == 'U') { dy = 1; }
    if (c == 'D') { dy = -1; }
    x += dx; y += dy;
    if (h == 0) { std::cout << "No"; return 0; }
    --h;
    if (mp[x][y] && h < k) { h = k; mp[x][y] = 0; }
  }
  std::cout << "Yes";
  return 0;
}
