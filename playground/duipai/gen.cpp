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
  
  srand((unsigned)time(0));

  const int n = 1 + rand() % (int)100;
  const int l = rand() % 10 + 1;
  std::cout << n; NL;
  orep(i, 0, n) {
    const int a = 1 + rand() % 10000;
    std::cout << a << " " << a / (l+rand()%10); NL;
  }

  return 0;
}
