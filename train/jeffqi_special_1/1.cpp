#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 3e6+5;
int arr[maxN], ret[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    std::cin >> arr[i];
  }
  std::vector<std::pair<int, int>> stk;
  for(int i = n-1; i >= 0; --i) {
    while(stk.size() && stk.back().first <= arr[i]) { stk.pop_back(); }
    if (stk.size()) { ret[i] = stk.back().second; }
    stk.push_back({arr[i], i+1});
  }
  orep(i, 0, n) { std::cout << ret[i] << " "; }


  return 0;
}
