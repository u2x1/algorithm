#include <iostream>
#include <algorithm>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e7+5;
int ret[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, p, q; std::cin >> n >> m >> p >> q;
  std::set<int> idx;
  orep(i, 1, n+1) { idx.insert(i); }
  for(int i = m; i > 0; --i) {
    int l = std::min((i*p+q)%n+1, (i*q+p)%n+1);
    int r = std::max((i*p+q)%n+1, (i*q+p)%n+1);
    auto fst = idx.lower_bound(l);
    if (fst == idx.end() || *fst > r) { continue; }
    auto fnl = fst;
    while(fnl != idx.end() && *fnl <= r) {
      ret[*fnl] = i;
      ++fnl;
    }
    idx.erase(fst, fnl);
  }
  orep(i, 1, n+1) { std::cout << ret[i]; NL; }

  return 0;
}
