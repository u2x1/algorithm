#include <iostream>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e5+5;
int mx[maxN][21];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 1, n+1) { std::cin >> mx[i][0]; }
  orep(j, 1, 21) {
    for(int i = 1; i+(1<<j)-1 <= n; ++i) {
      mx[i][j] = std::max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
    }
  }
  orep(i, 0, m) {
    int l, r; std::cin >> l >> r;
    int k = log2(r-l+1);
    std::cout << std::max(mx[l][k], mx[r-(1<<k)+1][k]); NL;
  }
  return 0;
}
