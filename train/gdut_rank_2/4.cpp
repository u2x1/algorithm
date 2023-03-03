#include <iostream>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    int tmp; std::cin >> tmp;
    if (tmp == 1) { std::cout << "No"; NL; continue; }
    const int bound = sqrt(tmp) + 1;
    orep(j, 2, bound) {
      if (tmp % j == 0) {
        std::cout << "No"; NL;
        goto fend;
      }
    }
    std::cout << "Yes"; NL;
fend:;
  }

  return 0;
}
