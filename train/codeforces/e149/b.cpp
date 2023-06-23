#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int _; std::cin >> _;
    std::string s; std::cin >> s;
    int ret = 2;
    int x = 2;
    orep(i, 1ul, s.size()) {
      if (s[i] == s[i-1]) { ++x; ret = std::max(ret, x); }
      else { x = 2; }
    }
    std::cout << ret; NL;
  }

  return 0;
}
