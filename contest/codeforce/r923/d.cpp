#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct DSU {
  std::vector<int> fa;
  DSU (int n) : fa(n) { std::iota(all(fa), 0); }
  int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
  void merge(int u, int v) { fa[find(v)] = find(u); }
};

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    DSU dsu(n);
    int last = -1;
    for (int i = 0; i < n; ++i) {
      int x; std::cin >> x;
      if (x == last) { dsu.merge(i, i-1); }
      last = x;
    }
    int q; std::cin >> q;
    while (q--) {
      int l, r; std::cin >> l >> r;
      --l, --r;
      int nxt = dsu.find(l) + 1;
      if (nxt > r) {
        std::cout << "-1 -1"; NL;
      } else {
        std::cout << l+1 << " " << nxt+1; NL;
      }
    } NL;
  }

  return 0;
}
