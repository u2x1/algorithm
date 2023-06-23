#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

void f(long long &x) {
  if (x % 200) {
    x = x * 1000 + 200;
  } else {
    x /= 200;
  }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, k; std::cin >> n >> k;
  while(k--) {
    f(n);
  }
  std::cout << n;

  return 0;
}
