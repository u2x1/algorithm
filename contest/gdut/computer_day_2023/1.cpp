#include <iostream>
#include <cmath>
#include <climits>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int x; std::cin >> x;
    if (x <= 2) { std::cout << -1; NL; continue; }
    x <<= 1;
    const int bound = sqrt(x)+1;
    int mi = 0x3f3f3f3f;
    orep(y, 1, bound) {
      if (x % y) { continue; }
      const int oth = x / y;

      const int n = y;
      if ((oth-(n-1)) % 2 == 0 && n >= 6) { mi = std::min(mi, n); }
      const int n2 = oth;
      if ((y-(n2-1)) % 2 == 0 && n2 >= 6) { mi = std::min(mi, n2); }
    }
    std::cout << mi; NL;
  }

  return 0;
}
