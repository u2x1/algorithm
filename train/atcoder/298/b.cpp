#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::vector<int>> a(n, std::vector<int>(n)), b(n, std::vector<int>(n));
  orep(i, 0, n) {
    orep(j, 0, n) {
      std::cin >> a[i][j];
    }
  }
  orep(i, 0, n) {
    orep(j, 0, n) {
      std::cin >> b[i][j];
    }
  }
  orep(k, 0, 4) {
    bool no = 0;
    orep(i, 0, n) {
      orep(j, 0, n) {
        if (a[i][j] && !b[i][j]) { no = 1; break; }
      }
    }
    if(!no) { std::cout << "Yes"; exit(0); }
    std::vector<std::vector<int>> newa(n, std::vector<int>(n));
    orep(i, 0, n) {
      orep(j, 0, n) {
        newa[i][j] = a[n-1-j][i];
      }
    }
    a = newa;
  }
  std::cout << "No";

  return 0;
}
