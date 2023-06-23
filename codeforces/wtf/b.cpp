#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int _; std::cin >> _;
  while(_--) {
    int n; std::cin >> n;
    std::vector<long long> pos(0), neg(0);
    long long x;
    orep(i, 0, n) {
      std::cin >> x;
      if (x >= 0) { pos.emplace_back(x); }
      else { neg.emplace_back(x); }
    }
    std::sort(pos.rbegin(), pos.rend());
    std::sort(neg.begin(), neg.end());
    if (pos.size() > 2) { pos.resize(2); }
    if (neg.size() > 2) { neg.resize(2); }
    std::vector<long long> f(0);
    for(auto y : pos) { f.emplace_back(y); }
    for(auto y : neg) { f.emplace_back(y); }
    long long ret = f[0] * f[1];
    orep(i, 0ul, f.size()) {
      orep(j, 0ul, i) {
        ret = std::max(ret, f[i]*f[j]);
      }
    }
    std::cout << ret; NL;
  }

  return 0;
}
