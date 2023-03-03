#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int amax, bmax; std::cin >> amax >> bmax;
  int n; std::cin >> n;
  int acur = 0, bcur = 0;
  orep(i,0,n) {
    int acall, agive, bcall, bgive; std::cin >> acall >> agive >> bcall >> bgive;
    int callsum = acall + bcall;
    if (agive != callsum && bgive != callsum) {
      continue;
    }
    if (agive == callsum && bgive == callsum) {
      continue;
    }
    if (agive == callsum) {
      acur++;
    }
    if (bgive == callsum) {
      bcur++;
    }

    if (acur > amax) {
      std::cout << "A"; NL;
      std::cout << bcur;
      return 0;
    } else if (bcur > bmax) {
      std::cout << "B"; NL;
      std::cout << acur;
      return 0;
    }
  }

  return 0;
}
