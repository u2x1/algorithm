#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 0, 3) { std::cin >> arr[i]; }
  std::sort(arr, arr+3);
  std::cout << (arr[0]+arr[2] == 2*arr[1] ? "Yes" : "No");
  return 0;
}
