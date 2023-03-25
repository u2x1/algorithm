#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long x1, x2, x3, x4, h; std::cin >> x1 >> x2 >> x3 >> x4 >> h;
  // if (x1 > x2) { std::swap(x1, x2); }
  // if (x3 > x4) { std::swap(x3, x4); }

  if (x1 > x3) { std::swap(x1,x3); std::swap(x2, x4); }
  if (x4 <= x2) { std::cout << h*(x4-x3); return 0; }
  if (x2 <= x3) { std::cout << "0"; return 0; }
  std::cout << h*(x2-x3); return 0;
}
