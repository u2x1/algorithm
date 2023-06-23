#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int a[maxN], b[maxN], c[5][5];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    std::cin >> a[i];
    b[i] = a[i];
  }
  std::sort(b, b+n);
  int ret = n;
  orep(i, 0, n) { c[a[i]][b[i]]++; }
  orep(i, 1, 5) { ret -= c[i][i]; c[i][i] = 0; }
  orep(i, 1, 5) {
    orep(j, 1, 5) {
      int x = std::min(c[i][j], c[j][i]);
      ret -= x;
      c[i][j] -= x; c[j][i] -= x;
    }
  }
  orep(i, 1, 5) {
    orep(j, 1, 5) {
      orep(k, 1, 5) {
        int x = std::min({c[i][j], c[j][k], c[k][i]});
        ret -= x;
        c[i][j] -= x; c[j][k] -= x; c[k][i] -= x;
      }
    }
  }
  orep(i, 2, 5) { ret -= c[1][i]; }
  std::cout << ret;

  return 0;
}
