#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> v1, v2;
  int tmp;
  orep(i, 0, n) {
    std::cin >> tmp;
    if (tmp & 1) { v1.emplace_back(tmp); }
    else { v2.emplace_back(tmp); }
  }
  int ret = -1;
  if (v1.size() > 1) {
    int a = 0, b = 0;
    for(auto &x : v1) {
      if (x >= a) { b = a; a = x; }
      else if (x > b) { b = x; }
    }
    ret = std::max(a+b, ret);
  }
  if (v2.size() > 1) {
    int a = 0, b = 0;
    for(auto &x : v2) {
      if (x >= a) { b = a; a = x; }
      else if (x > b) { b = x; }
    }
    ret = std::max(a+b, ret);
  }
  std::cout << ret;

  return 0;
}
