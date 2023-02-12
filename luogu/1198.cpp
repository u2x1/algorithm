#include <iostream>
#include <cmath>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
int mx[maxN][22];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int m, d; std::cin >> m >> d;
  int cnt = 0;
  int t = 0;
  orep(i, 0, m) {
    char c; int x; std::cin >> c >> x;
    if (c == 'A') {
      mx[cnt][0] = (x+t)%d;
      for (int j = 1; cnt-(1<<j)+1 >= 0; ++j) {
        mx[cnt][j] = std::max(mx[cnt][j-1], mx[cnt-(1<<(j-1))][j-1]);
      }
      ++cnt;
    } else {
      int k = log2(x);
      t = std::max(mx[cnt-1][k], mx[cnt-1-(x-(1<<k))][k]);
      std::cout << t; NL;
    }
  }

  return 0;
}
