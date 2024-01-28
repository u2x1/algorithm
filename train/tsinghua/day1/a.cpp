#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  std::vector<int> o, z;
  for(int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') { o.emplace_back(i+1); }
    if (s[i] == '0') { z.emplace_back(i+1); }
  }
  std::pair<int, std::pair<int, int>> ret = { 0, {0, 0} };
  if (o.size() > 1) { ret = std::max(ret, { o.back()-o.front()+1, { o.front(), o.back() } }); }
  if (z.size() > 1) { ret = std::max(ret, { z.back()-z.front()+1, { z.front(), z.back() } }); }
  auto [a, b] = ret;
  auto [x, y] = b;
  std::cout << x << " " << y-1 << " " << x+1 << " " << y;

  return 0;
}
