#include <iostream>
#include <cstring>
#include <map>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, k; std::cin >> n >> k;
    int tmp;
    memset(arr, 0, sizeof(int)*n);
    orep(i, 0, n) { std::cin >> tmp; arr[i%k] += tmp; }
    std::map<int, int> mp;
    orep(i, 0, k) { mp[arr[i]]++; }
    int ret = k;
    for(const auto [a, b]:mp) {
      ret = std::min(ret, k-b);
    }
    std::cout << ret; NL;
  }

  return 0;
}
