#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<long long> v1(n), v2(n);
  for(auto &x : v1) { std::cin >> x; }
  for(auto &x : v2) { std::cin >> x; }
  std::cout << *std::max_element(v1.begin(), v1.end()) + std::accumulate(v2.begin(), v2.end(), 0ll) - *std::max_element(v2.begin(), v2.end());

  return 0;
}
