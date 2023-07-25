#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

struct Info { int l, r; int val; };
Info operator+(const Info a, const Info b) {
  return { a.l, b.r, a.val + b.val };
}

struct SegTree {
  std::vector<Info> t; int n;
  std::vector<int> lz;

  void apply(int p, int x) {
    Info &y = t[p];
    y.val += x * (y.r - y.l);
    lz[p] += x;
  }

  void pushup(int p) { t[p] = t[p*2] + t[p*2+1]; }

  void pushdn(int p) {
    apply(p*2, lz[p]);
    apply(p*2+1, lz[p]);
    lz[p] = 0;
  }

  void add(int x, int l, int r, int p) {
    const Info &u = t[p];
    if (l <= u.l && u.r <= r) { apply(p, x); return; }
    pushdn(p);
    if (l < t[p*2].r) { add(x, l, r, p*2); }
    if (r > t[p*2+1].l) { add(x, l, r, p*2+1); }
    pushup(p);
  }

  int sum(int l, int r, int p) {
    const Info &u = t[p];
    if (l <= u.l && u.r <= r) { return t[p].val; }
    pushdn(p);
    int ret = 0;
    if (l < t[p*2].r) { ret += sum(l, r, p*2); }
    if (r > t[p*2+1].l) { ret += sum(l, r, p*2+1); }
    return ret;
  }

  void build(int l, int r, int p) {
    t[p] = {l, r, 0};
    if (l == r-1) { return; }
    int m = (l+r) / 2;
    build(l, m, p*2); build(m, r, p*2+1);
    pushup(p);
  }

  SegTree(int nn) {
    n = nn+5;
    t = std::vector<Info>(n*4);
    lz = std::vector<int>(n*4);
    build(0, n, 1);
  };
};

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, q; std::cin >> n >> m >> q;
  SegTree t(n+1);
  std::vector<std::pair<int, int>> lr;
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    lr.push_back({a, b+1});
    t.add(1, b, b+1, 1);
  }
  std::sort(all(lr));
  std::vector<std::array<int, 3>> qr;
  orep(i, 0, q) {
    int a, b; std::cin >> a >> b;
    qr.push_back({a, b+1, i});
  }
  std::sort(all(qr));
  std::vector<int> ret(q);
  int pos = 0;
  for(auto [l, r, idx] : qr) {
    while(pos < m && lr[pos].first < l) { t.add(-1, lr[pos].second-1, lr[pos].second, 1);  ++pos; }
    ret[idx] = t.sum(0, r, 1);
  }
  for(auto x : ret) { std::cout << x; NL; }

  return 0;
}
