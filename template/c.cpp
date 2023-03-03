#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e2+5;
int arr[maxN];
int c[maxN][maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 0, 10) {
    orep(j, 0, i+1) {
      if (!j) { c[i][j] = 1; continue; }
      c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
  }
  orep(i, 0, 10) {
    orep(j, 0, i+1) {
      std::cout << "c("<< i << ','<< j << ") = "  << c[i][j]; NL;
    }
  }

  return 0;
}
