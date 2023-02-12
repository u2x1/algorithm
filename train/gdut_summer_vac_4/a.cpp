#include <iostream>
#include <cmath>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, k; std::cin >> n >> k;
  long long x = pow(10, k);
  std::cout << x*n/std::__gcd(x, n);

  return 0;
}
