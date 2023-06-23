#include <iostream>
#include <random>
#include <chrono>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  
  srand(std::chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
  std::cout << t; NL;
  while(t--) {
    // const int maxN = 20;
    // const int m = (1+rand() % maxN);
    const int n = (1+rand() % 10);
    // std::cout << n << " " << m; NL;
    std::cout << n; NL;
    orep(i, 0, n) {
      int l = rand() % 100;
      int r = l + rand() % 20;
      std::cout << l << " " << r; NL;
    }
  }

  return 0;
}
