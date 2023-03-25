#include <iostream>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << abs(a-c)+abs(b-d); NL;
  }

  return 0;
}
