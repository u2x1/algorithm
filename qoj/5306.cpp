#pragma GCC optimize(3)
#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct Info {
  int mx, mc, sx; lnt sum;
};

Info operator+(Info x, Info y) {
  if (x.mx != y.mx) {
    if (x.mx < y.mx) { std::swap(x, y); }
    return { x.mx, x.mc, std::max(x.sx, y.mx), x.sum + y.sum };
  } else {
    return { x.mx, x.mc + y.mc, std::max(x.sx, y.sx), x.sum + y.sum };
  }
}

std::vector<Info> t;

struct SegTree {

  int n;

  inline void pushup(int p, int mid) {
    t[p] = t[mid*2] + t[mid*2|1];
  }

  inline void pushdn(int p, int mid) {
    if (t[p].mx < t[mid*2].mx) {
      t[mid*2].sum -= 1ll * t[mid*2].mc * (t[mid*2].mx - t[p].mx);
      t[mid*2].mx = t[p].mx;
    }
    if (t[p].mx < t[mid*2|1].mx) {
      t[mid*2|1].sum -= 1ll * t[mid*2|1].mc * (t[mid*2|1].mx - t[p].mx);
      t[mid*2|1].mx = t[p].mx;
    }
  }

  void upd(int x, int l, int r, int cl, int cr, int p) {
    if (t[p].mx <= x) { return; }
    if (l <= cl && cr <= r && x > t[p].sx) {
      t[p].sum -= 1ll * t[p].mc * (t[p].mx - x);
      t[p].mx = x;
      return;
    }
    int mid = cl + ((cr-cl) >> 1);
    pushdn(p, mid);
    if (l < mid) { upd(x, l, r, cl, mid, mid*2); }
    if (r > mid) { upd(x, l, r, mid, cr, mid*2|1); }
    pushup(p, mid);
  }

  Info qry(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) { return t[p]; }
    int mid = cl + ((cr - cl) >> 1);
    pushdn(p, mid);
    if (mid >= r) { return qry(l, r, cl, mid, mid*2); }
    if (mid <= l) { return qry(l, r, mid, cr, mid*2|1); }
    return qry(l, r, cl, mid, mid*2) + qry(l, r, mid, cr, mid*2|1);
  }

  SegTree(const std::vector<int> &v) {
    n = v.size();
    t.resize(n * 2);
    auto build = [&](auto &&self, int l, int r, int p) -> void {
      if (l == r-1) { t[p] = { v[l], 1, -1, v[l] }; return; }
      int mid = l + ((r-l) >> 1);
      self(self, l, mid, mid*2); self(self, mid, r, mid*2|1);
      pushup(p, mid);
    };
    build(build, 0, n, 1);
  }
};

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {
    int n, m; std::cin >> n >> m;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> v[i];
    }
    SegTree segTree(v);
    for (int i = 0; i < m; ++i) {
      int o, u, v; std::cin >> o >> u >> v; --u;
      if (o == 0) {
        int x; std::cin >> x;
        segTree.upd(x, u, v, 0, segTree.n, 1);
      } else if (o == 1) {
        std::cout << segTree.qry(u, v, 0, segTree.n, 1).mx; NL;
      } else if (o == 2) {
        std::cout << segTree.qry(u, v, 0, segTree.n, 1).sum; NL;
      }
    }
  }

  return 0;
}


