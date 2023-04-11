#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e3+5;
int x[maxN], y[maxN];
int dp[maxN][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, d; std::cin >> n >> d;
  orep(i, 0, n) { std::cin >> x[i]; }
  orep(i, 0, n) { std::cin >> y[i]; }
  orep(i, 0, n) {
    orep(dd, -1000, 1001) {
    }
  }

  return 0;
}
