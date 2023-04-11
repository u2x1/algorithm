#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
long long fib[maxN] = {1, 1};

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 2, 50) { fib[i] = fib[i-1] + fib[i-2]; }
  int t; std::cin >> t;
  while(t--) {
    long long n, x, y; std::cin >> n >> y >> x;
    long long w = fib[n+1], h = fib[n]; 
    while(n >= 2) {
      if (x <= h && w-x+1 <= h) { std::cout << "NO"; goto fend; }
      if (x > h) { x -= h; }
      std::swap(x, y);
      --n; w = fib[n+1], h = fib[n];
    }
    std::cout << "YES";
fend:NL;
  }


  return 0;
}
