#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

long long arr[2];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    arr[0] = arr[1] = 0;
    orep(i, 0, n) {
      int tmp; std::cin >> tmp;
      arr[i%2] += tmp;
    }
    if (n & 1 || arr[0] <= arr[1]) { std::cout << "YES"; NL; }
    else { std::cout << "NO"; NL; }
  }

  return 0;
}
