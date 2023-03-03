#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e3+5;
int arr[maxN];
int genders[maxN]; int cnt;
std::string boy[maxN]; int bcnt;
std::string girl[maxN]; int gcnt;
std::string all[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    std::cin >> genders[cnt] >> all[cnt];
    std::string &s = all[cnt++];
    if (genders[cnt-1]) {
      boy[bcnt++] = s;
    } else {
      girl[gcnt++] = s;
    }
  }

  gcnt--; bcnt--;
  orep(i, 0, n/2) {
    std::cout << all[i];
    std::cout << " ";
    if (genders[i]) {
      std::cout << girl[gcnt--];
    } else {
      std::cout << boy[bcnt--];
    }
    NL;
  }


  return 0;
}
