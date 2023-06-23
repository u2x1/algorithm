#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> v(n+1);
  orep(i, 0, m) {
    int k; std::cin >> k;
    orep(j, 0, k) {
      int x; std::cin >> x;
      v[x].emplace_back(i);
    }
  }
  orep(i, 1, n) {
    orep(j, 1, i) {
      auto a = 0ul, b = 0ul;
      bool flag = 0;
      if (!v[i].size() || !v[j].size()) { std::cout << "No"; exit(0); }
      while(a != v[i].size() && b != v[j].size()) {
        if (v[i][a] == v[j][b]) { flag = 1; break; }
        if (b == v[j].size()-1 || (a < v[i].size() && v[i][a] < v[j][b])) { ++a; }
        else { ++b; }
      }
      if (flag == 0) { std::cout << "No"; exit(0); }
    }
  }
  std::cout << "Yes";

  return 0;
}
