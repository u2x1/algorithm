#include <iostream>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 3e5+5;
int ret[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::set<int> idx;
  orep(i, 1, n+1) { idx.insert(i); }
  orep(i, 0, m) {
    int l, r, x; std::cin >> l >> r >> x;
    auto fst = idx.lower_bound(l);
    if (fst == idx.end() || *fst > r) { continue; }
    auto fnl = fst;
    while(fnl != idx.end() && *fnl <= r) {
      ret[*fnl] = x; ++fnl;
    }
    idx.erase(fst, fnl);
    idx.insert(x);
  }
  orep(i, 1, n+1) {
    std::cout << (ret[i] == i ? 0 : ret[i]) << " ";
  }

  return 0;
}
