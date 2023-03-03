#include <iostream>
#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int h; std::cin >> h;
  long long ret = (h * 10 - 1000) * 9 * 2;
  ret /= 10;
  std::cout << ret / 10  << "." << ret % 10;


  return 0;
}
