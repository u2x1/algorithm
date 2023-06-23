#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'
#define all(x)      x.begin(), x.end()

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  std::vector<int> v(n+1); std::iota(all(v), 0);
  std::vector<int> pos(n+1); std::iota(all(pos), 0);
  while(k--) {
    int x; std::cin >> x;
    int nxt = pos[x] == n ? v[pos[x]-1] : v[pos[x]+1];
    std::swap(v[pos[x]], v[pos[nxt]]);
    std::swap(pos[x], pos[nxt]);
  }
  orep(i, 1, n+1) { std::cout << v[i] << " "; }

  return 0;
}
