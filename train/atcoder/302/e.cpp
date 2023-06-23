#include <iostream>
#include <vector>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q; std::cin >> n >> q;
  int ret = n;
  std::vector<std::set<int>> v(n+1);
  orep(i, 0, q) {
    int e; std::cin >> e;
    if (e == 1) {
      int a, b; std::cin >> a >> b;
      if (!v[a].size()) { ret--; }
      if (!v[b].size()) { ret--; }
      v[a].insert(b);
      v[b].insert(a);
    } else {
      int a; std::cin >> a;
      for(auto x : v[a]) {
        v[x].erase(v[x].lower_bound(a));
        if (!v[x].size()) { ++ret; }
      }
      if (v[a].size()) { ++ret; }
      v[a].clear();
    }
    std::cout << ret; NL;
  }

  return 0;
}
