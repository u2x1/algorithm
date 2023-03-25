#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, k; std::cin >> n >> k;
  long long a = 0, b = 0;
  orep(i, 1, n+1) {
    long long c; std::cin >> c;
    a = b; b = c;
  }
  if (a <= b) { std::cout << "Python will never be faster than C++"; return 0; }
  else {
    while(1) {
      ++n;
      long long c = std::max(0ll, 2*b-a);
      if (c < k) { std::cout << "Python 3." << n << " will be faster than C++"; return 0; }
      a = b; b = c;
    }
  }

  return 0;
}
