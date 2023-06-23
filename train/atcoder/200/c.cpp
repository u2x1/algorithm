#include <iostream>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::map<int, long long> mp;
  orep(i, 0, n) { long long tmp; std::cin >> tmp; mp[tmp%200]++; }
  long long ret = 0;
  for(auto [_, x] : mp) {
    if (x > 1) { ret += x*(x-1)/2; }
  }
  std::cout << ret;

  return 0;
}
