#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int l, r, p; std::cin >> l >> r >> p;
  if (l == r) {
    std::cout << "Ambidextrous"; return 0;
  } else if (l > r) {
    if (l*p <= r*100) {
      std::cout << "Ambidextrous"; 
    } else {
      std::cout << "Left-handed";
    }
  } else if (r > l) {
    if (r*p <= l*100) {
      std::cout << "Ambidextrous"; 
    } else {
      std::cout << "Right-handed";
    }
  }



  return 0;
}
