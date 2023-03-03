#include <iostream>
#include <cmath>
#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int h; std::cin >> h;
    long long perf = ((h * 10 - 1000) * 9 * 2) / 10 / 10;
    int w; std::cin >> w;
    if (abs(w-perf)*10 < perf) {
      std::cout << "You are wan mei!";
    } else if ((w-perf)*10 >= perf) {
      std::cout << "You are tai pang le!";
    } else {
      std::cout << "You are tai shou le!";
    }
    NL;
  }


  return 0;
}
