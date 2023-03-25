#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int x = 6;
  int rst = 0;
  orep(i, 0, x) {
    orep(j, i, x) {
      const int y = i^j;
      orep(k, 0, 3) {
        std::cout << ((j>>(2-k))&1); 
      } std::cout <<  " ";
      orep(k, 0, 3) {
        std::cout << ((i>>(2-k))&1); 
      } std::cout <<  " ";
      orep(k, 0, 3) {
        rst += (y>>(2-k)) & 1;
        std::cout << ((y>>(2-k))&1); 
      } NL;
    }
  }
  std::cout << rst;

  return 0;
}
