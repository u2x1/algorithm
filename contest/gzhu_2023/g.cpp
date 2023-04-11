#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 5e3+5;
const int mod = 1e9+7;
int arr[maxN];

int c[maxN][maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  c[0][0] = 1;
  orep(i, 1, maxN) {
    c[i][0] = 1;
    orep(j, 1, maxN) {
      c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
  }
  int t; std::cin >> t;
  while(t--) {
    int a, b; std::cin >> a >> b;
    if (a >= b) { std::cout << -1; NL; continue; }
    std::cout << c[b][a+1]; NL;
  }

  return 0;
}
