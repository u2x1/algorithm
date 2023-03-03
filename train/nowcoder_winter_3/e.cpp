#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
  if ((x1+x2 - 2*y2 + (y2+y1)) % 2 || (y1+y2 + 2*x2 - (x2+x1)) % 2) { std::cout << "No Answer!"; return 0; }
  std::cout << (x1+x2 - 2*y2 + (y2+y1)) / 2 << " " << (y1+y2 + 2*x2 - (x2+x1)) / 2;
  return 0;
}
