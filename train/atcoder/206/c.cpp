#include <iostream>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n; std::cin >> n;
  std::map<int, long long> mp;
  long long tmp;
  orep(i, 0, n) { std::cin >> tmp; mp[tmp]++; }
  long long ret = n * (n-1) / 2;
  for(auto [x, y] : mp) {
    ret -= y * (y-1) / 2;
  }
  std::cout << ret;

  return 0;
}
