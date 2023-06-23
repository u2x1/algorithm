#include <iostream>
#include <algorithm>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
std::pair<int, std::string> arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int N; std::cin >> N;
  orep(i, 0, N) { std::cin >> arr[i].second >> arr[i].first; }
  std::sort(arr, arr+N);
  std::cout << arr[N-2].second;

  return 0;
}
