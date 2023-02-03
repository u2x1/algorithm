#include <iostream>
#include <iomanip>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cout << std::setprecision(15);
  double x, l, r; std::cin >> x >> l >> r;
  if (l >= x) { std::cout << "0"; return 0; }
  if (x > r) { std::cout << "1"; return 0; }
  std::cout << (x-l) / (r-l+1);
  return 0;
}
