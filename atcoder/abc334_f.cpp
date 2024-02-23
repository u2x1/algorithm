#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct SegTree {
  std::vector<double> t, f;
  int n;
  SegTree(int nn) {
    n = nn;
    t.resize(n*4);
    f.resize(n*4);
  }

  void apply(int p, double x) { t[p] += x; f[p] += x; }

  void pushup(int p) { t[p] = std::min(t[p*2], t[p*2+1]); }

  void pushdn(int p) {
    apply(p*2, f[p]);
    apply(p*2+1, f[p]);
    f[p] = 0;
  }

  void add(int l, int r, double x, int cl, int cr, int p) {
    if (l >= r) { return; }
    if (l <= cl && cr <= r) { apply(p, x); return; }
    int mid = cl + ((cr - cl) >> 1);
    pushdn(p);
    if (l < mid) { add(l, r, x, cl, mid, p*2); }
    if (r > mid) { add(l, r, x, mid, cr, p*2+1); }
    pushup(p);
  }

  void add(int l, int r, double x) { return add(l, r, x, 0, n, 1); }

  double ask(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) { return t[p]; }
    int mid = cl + ((cr - cl) >> 1);
    pushdn(p);
    if (r <= mid) { return ask(l, r, cl, mid, p*2); }
    if (l >= mid) { return ask(l, r, mid, cr, p*2+1); }
    return std::min(ask(l, r, cl, mid, p*2), ask(l, r, mid, cr, p*2+1));
  }

  double ask(int l, int r) { return ask(l, r, 0, n, 1); }
};

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  int sx, sy; std::cin >> sx >> sy;
  SegTree segTree(n+1);
  auto dis = [&](lnt ax, lnt ay, lnt bx, lnt by) {
    return std::sqrt(double((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
  };
  int lx = sx, ly = sy;
  for (int i = 1; i <= n; ++i) {
    int x, y; std::cin >> x >> y;
    // if (i == 1) {
    //   segTree.add(1, 2, dis(sx, sy, x, y));
    //   std::cout << dis(sx, sy, x, y); NL;
    //   lx = x; ly = y;
    //   continue;
    // }
    if (i > 1) { segTree.add(i-1, i, dis(lx, ly, sx, sy) + dis(x, y, sx, sy)); }
    segTree.add(0, i-(i != 1), dis(lx, ly, x, y));
    segTree.add(i, i+1, segTree.ask(std::max(0, i - k), i));
    // for (int i = 0; i < n; ++i) { std::cout << segTree.ask(i, i+1) << " "; } NL;
    lx = x; ly = y;
  }
  std::cout << std::fixed << std::setprecision(15);
  std::cout << segTree.ask(n, n+1) + dis(lx, ly, sx, sy);

  return 0;
}
