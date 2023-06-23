#include <iostream>
#include <vector>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v;
    bool down = 0;
    orep(i, 0, n) {
      int x; std::cin >> x;
      if (v.empty()) { v.emplace_back(x); std::cout << '1'; continue; }
      if (down) {
        if (x >= v.back() && x <= v.front()) {
          v.emplace_back(x); std::cout << '1';
        } else {
          std::cout << '0';
        }
      } else {
        if (x < v.back()) {
          if (x <= v.front()) {
            v.emplace_back(x); std::cout << '1';
            down = 1;
          } else {
            std::cout << '0';
          }
        } else {
          v.emplace_back(x); std::cout << '1';
        }
      }
    } NL;
  }

  return 0;
}
