#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    int al, ar, bl, br; std::cin >> al >> ar >> bl >> br;
    if (bl > n - al) { std::cout << 0; NL; continue; }
    if (br < n - ar) { std::cout << 0; NL; continue; }
    int brr = std::min(n-al, br);
    int bll = std::max(n-ar, bl);
    std::cout << brr - bll + 1; NL;
  }

  return 0;
}
