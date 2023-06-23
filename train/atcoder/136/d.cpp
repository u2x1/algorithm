#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  std::vector<int> ret(s.size());
  orep(i, 0ul, s.size()) {
    int rpos, lpos;
    int rs = 0, ls = 0;
    while(i < s.size() && s[i] == 'R') { ++i; ++rs; } rpos = i-1;
    while(i < s.size() && s[i] == 'L') { ++i; ++ls; } lpos = rpos+1;
    --i;
    ret[rpos] = (rs+1)/2 + ls/2;
    ret[lpos] = (ls+1)/2 + rs/2;
  }
  for(auto x : ret) { std::cout << x << " "; }

  return 0;
}
