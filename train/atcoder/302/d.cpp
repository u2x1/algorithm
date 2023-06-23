#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, m, d; std::cin >> n >> m >> d;
  std::vector<long long> s1, s2; long long tmp;
  orep(i, 0, n) { std::cin >> tmp; s1.push_back(tmp); }
  orep(i, 0, m) { std::cin >> tmp; s2.push_back(tmp); }
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  if (s1.back() < s2.back()) { std::swap(s1, s2); }
  while(s1.size() && s2.size()) {
    auto x = s1.back();
    auto it = std::prev(std::upper_bound(s2.begin(), s2.end(), x+d));
    if (x-*it <= d) { std::cout << *it + x; exit(0); }
    s1.pop_back();
    if (s1.size() && s2.size() && s1.back() < s2.back()) { std::swap(s1, s2); }
  }
  std::cout << -1;
  

  return 0;
}
