#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int h, w; std::cin >> h >> w;
  orep(i, 0, h) {
    orep(j, 0, w) {
      int tmp; std::cin >> tmp;
      char c = (!tmp ? '.' : 'A'+tmp-1);
      std::cout << c;
    } NL;
  }

  return 0;
}
