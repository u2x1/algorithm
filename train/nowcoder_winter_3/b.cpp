#include <iostream>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    long long n; std::cin >> n;
    if (n == 2) { std::cout << -1; NL; continue; }
    long long k = (n+1) >> 1;
    std::cout << (n-k)/3+k;
    NL;
  }

  return 0;
}
