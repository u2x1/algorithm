#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v;
    int tmp; std::cin >> tmp;
    v.emplace_back(tmp);
    orep(i, 2, n) {
      if (v.back() > tmp) { v.back() = tmp; }
      v.emplace_back(tmp);
      std::cin >> tmp;
    }
    if (v.back() > tmp) { v.back() = tmp; }
    v.emplace_back(tmp);
    for(int x : v) { std::cout << x << " "; } NL;
  }

  return 0;
}
