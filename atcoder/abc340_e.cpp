#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct SegTree {
  std::vector<lnt> t, f;
  int n;
  SegTree(const std::vector<int> &v) {
    n = v.size();
    t.resize(n * 2);
    f.resize(n * 2);
    auto build = [&](auto &&self, int l, int r, int p) {
      if (l == r - 1) { t[p] = v[l]; return; }
      int mid = l + ((r - l) >> 1);
      self(self, l, mid, mid * 2);
      self(self, mid, r, mid * 2 + 1);
    };
    build(build, 0, n, 1);
  }

  inline void apply(int p, lnt x) {
    t[p] += x; f[p] += x;
  }

  void pushdn(int p, int mid) {
    apply(mid * 2, f[p]);
    apply(mid * 2 + 1, f[p]);
    f[p] = 0;
  }

  void add(int l, int r, lnt x, int cl, int cr, int p) {
    if (l <= cl && cr <= r) { apply(p, x); return; }
    int mid = cl + ((cr - cl) >> 1);
    pushdn(p, mid);
    if (l < mid) { add(l, r, x, cl, mid, mid * 2); }
    if (r > mid) { add(l, r, x, mid, cr, mid * 2 + 1); }
  }

  lnt ask(int pos, int cl, int cr, int p) {
    if (pos == cl && cr == cl + 1) { return t[p]; }
    int mid = cl + ((cr - cl) >> 1);
    pushdn(p, mid);
    if (pos < mid) { return ask(pos, cl, mid, mid * 2); }
    else { return ask(pos, mid, cr, mid * 2 + 1); }
  }
  lnt ask(int pos) { return ask(pos, 0, n, 1); }
  void add(int l, int r, lnt x) { return add(l, r, x, 0, n, 1); }
};

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  SegTree segTree(v);
  for (int i = 0; i < m; ++i) {
    int x; std::cin >> x;
    lnt cur = segTree.ask(x);
    segTree.add(x, x+1, -cur);
    x = (x+1) % n;
    segTree.add(0, n, cur / n);
    cur %= n;
    if (cur == 0) { continue; }
    segTree.add(x, std::min<int>(n, x+cur), 1);
    if (x+cur > n) { segTree.add(0, x+cur-n, 1); }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << segTree.ask(i) << " ";
  }

  return 0;
}
