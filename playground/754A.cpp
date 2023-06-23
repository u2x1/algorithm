#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> v(n);
  bool no = 1;
  for(auto &x : v) { std::cin >> x; if (x) { no = 0; } }
  if (no) { std::cout << "NO"; return 0; }
  std::cout << "YES"; NL;
  std::vector<std::pair<int, int>> ret;
  bool flag = (v[0] == 0);
  int i = 0;
  while(v[i] == 0) { ++i; }
  int lpos = -1;
  orep(i, 0, n) {
    if (v[i]) { if (lpos != -1) { ret.emplace_back(lpos, i); lpos = -1; } else { ret.emplace_back(i, i); } continue; }
    lpos = i;
    while(i < n && v[i] == 0) {
      ++i;
    } --i;
  }
  if (v.back() == 0) {
    ret.back() = {ret.back().first, v.size()-1};
  }
  std::cout << ret.size(); NL;
  for(auto [x, y] : ret) {
    std::cout << x+1 << " " << y+1; NL;
  }


  return 0;
}
