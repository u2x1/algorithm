#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n;
  std::cin >> n;
  int x = 0; int i = 1;
  while(x < n) {
    x += i;
    i++;
  }
  std::cout << i-1;

  return 0;
}
