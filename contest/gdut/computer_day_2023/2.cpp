#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    long long n, a, d; std::cin >> n >> a >> d;
    long long g = std::__gcd(n, d);
    std::cout << n/g; NL;
  }

  return 0;
}
