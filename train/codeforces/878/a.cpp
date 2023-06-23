#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::string ret;
    orep(i, 0ul, s.size()) {
      char c = s[i];
      for(++i; i < s.size() && s[i] != c; ++i);
      ret += c;
    }
    std::cout << ret; NL;
  }

  return 0;
}
