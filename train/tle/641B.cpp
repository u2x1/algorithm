#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, q; std::cin >> n >> m >> q;
  std::vector<std::vector<int>> cx(n, std::vector<int>(m)), cy = cx;
  orep(i, 0, n) {
    orep(j, 0, m) {
      cx[i][j] = i;
      cy[i][j] = j;
    }
  }
  std::vector<std::vector<int>> ret(n, std::vector<int>(m));
  orep(_, 0, q) {
    int o, x, y, z; std::cin >> o >> x;
    if (o > 2) { std::cin >> y >> z; }
    --x, --y;
    if (o == 1) {
      orep(i, 1, m) { std::swap(cy[x][i], cy[x][i-1]); std::swap(cx[x][i], cx[x][i-1]); }
    } else if (o == 2) {
      orep(i, 1, n) { std::swap(cy[i][x], cy[i-1][x]); std::swap(cx[i][x], cx[i-1][x]); }
    } else {
      ret[cx[x][y]][cy[x][y]] = z;
    }
  }
  // std::reverse(all(qs));
  // int ox = 0, oy = 0;
  // for(auto [o, x, y, z] : qs) {
  //   --x, --y;
  //   if (o == 1) {
  //     ++ox;
  //   } else if (o == 2) {
  //     ++oy;
  //   } else {
  //     ret[(x+ox)%n][(y+oy)%m] = z;
  //   }
  // }
  for(auto v : ret) {
    for(auto x : v) {
      std::cout << x << " ";
    } NL;
  }


  return 0;
}
