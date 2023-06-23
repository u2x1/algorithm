#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 800+5;
int a[maxN][maxN];
int greater[maxN][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  std::vector<int> v;
  orep(i, 1, n+1) {
    orep(j, 1, n+1) {
      int x; std::cin >> x;
      a[i][j] = x;
      v.emplace_back(x);
    }
  }
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  int K = k*k/2;
  int l = -1,  r = v.size();
  const auto sSum = [&](int x, int y) { return greater[x][y] - greater[x-k][y] - greater[x][y-k] + greater[x-k][y-k]; };
  while(l < r-1) {
    int _m = (l + r) >> 1, m = v[_m];
    orep(i, 1, n+1) {
      orep(j, 1, n+1) {
        greater[i][j] = (a[i][j] > m) + greater[i][j-1] + greater[i-1][j] - greater[i-1][j-1];
      }
    }
    bool yes = 0;
    orep(i, k, n+1) {
      orep(j, k, n+1) {
         if (sSum(i, j) <= K) { yes = 1; }
      }
    }
    if (yes) { r = _m; }
    else { l = _m; }
  }
  std::cout << v[r];

  return 0;
}
