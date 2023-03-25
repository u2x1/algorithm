#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int price[9] = {0,7,27,41,49,63,78,108 };

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    long long sum = 0;
    orep(i, 0, n) {
      int tmp; std::cin >> tmp;
      sum += price[tmp];
    }
    if (sum >= 120) { sum -= 50; }
    else if (sum >= 89) { sum -= 30; }
    else if (sum >= 69) { sum -= 15; }
    std::cout << sum; NL;
  }

  return 0;
}
