#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0,  n) {
    int tmp;
    std::cin >> tmp;
    if (tmp & 1) { continue; }
    std::cout << tmp << " ";
  }

  return 0;
}
