#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int x = 0;
  orep(i, 1, 10000) {
    int rst;
    if (i%4 == 0) {
      rst = i;
    } else if (i%4 == 1) {
      rst = 1;
    } else if (i%4 == 2) {
      rst = i+1;
    } else if (i%4 == 3) {
      rst = 0;
    }
    if ((x^=i) == rst) { continue; }
    std::cout << i << " hit " ; NL; 
  }

  return 0;
}
