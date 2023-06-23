#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  int sum = 0;
  orep(i, 0, n) { std::cin >> arr[i]; sum += arr[i]; }
  std::vector<char> dp0, dp1(maxN, 0);
  dp1[0] = 1;
  orep(i, 0, n) {
    dp0 = dp1;
    orep(j, arr[i], maxN){
      dp1[j] |= dp0[j-arr[i]];
    }
  }
  int half = (sum+1)/2;
  int ret = half;
  while(!dp1[ret]) {
    ++ret;
  }
  std::cout << ret;

  return 0;
}
