#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, x1, y1, x2, y2; std::cin >> n >> x1 >> y1 >> x2 >> y2;
    int a = std::min(std::min(x1, n-x1+1), std::min(y1, n-y1+1));
    int b = std::min(std::min(x2, n-x2+1), std::min(y2, n-y2+1));
    std::cout << abs(a-b); NL;
  }

  return 0;
}
