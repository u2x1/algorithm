#include <iostream>
#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int hh, mm; char c; std::cin >> hh >> c >> mm;
  if ((hh == 12 && mm == 0) || (hh < 12)) {
    printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
    return 0;
  }
  hh -= 12;
  orep(i, 0, hh + (mm!=0)) {
    std::cout << "Dang";
  }
  return 0;
}
