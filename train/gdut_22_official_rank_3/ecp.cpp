#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 1, 400) {
    orep(j, 1, i) {
      for(int k = 0; j+k<=i; ++k) {
        int sum = 0;
        orep(z, 0, k) {
          sum += j+z;
          if (sum == i) { goto fend;}
        }
      }
    }
    std::cout << i << " no";
     NL;
fend:;
  }

  return 0;
}
