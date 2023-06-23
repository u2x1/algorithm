#include <iostream>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 50+5;
int arr[maxN];
bool f[maxN][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, m) {
    std::cin >> arr[0];
    orep(j, 1, n) {
      std::cin >> arr[j];
      f[arr[j-1]][arr[j]] = 1;
      f[arr[j]][arr[j-1]] = 1;
    }
  }
  int ret = 0;
  orep(i, 1, n+1) {
    int c = -1;
    orep(j, 1, n+1) {
      c += !f[i][j];
      // std::cout << f[i][j] << " ";
    }
    // std::cout << c; NL;
    ret += c;
  }
  std::cout << ret / 2;


  return 0;
}
