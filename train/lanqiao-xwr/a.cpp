#include <iostream>
#include <algorithm>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'
#define all(x)      x.begin(), x.end()

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  auto check = [](int x) {
    std::string s; 
    while(x) {
      s += '0'+(x%8);
      x /= 8;
    }
    std::string ss = s;
    std::reverse(all(ss));
    return ss == s;
  };
  for(int i = 1; i * i <= n; ++i) {
    int x = i*i;
    if (check(x)) { std::cout << x << " "; }
  }

  return 0;
}
