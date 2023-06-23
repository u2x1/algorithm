#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  for(auto &x: s) {
    if (x == '6') { x = '9'; }
    else if (x == '9') { x = '6'; }
  }
  std::reverse(s.begin(), s.end());
  std::cout << s;

  return 0;
}
