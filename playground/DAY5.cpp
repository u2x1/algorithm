#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

struct Info {
  int len; std::array<bool, 2> lc, rc; std::array<int, 2> lmx, rmx, mx;
};

const Info operator+(const Info& l, const Info &r) {
  Info ret = { l.len + r.len, l.lc, r.rc };
  for(int i = 0; i < 2; ++i) {
    if (l.rc[i] != r.lc[i]) {
      if (l.len == l.lmx[i]) { ret.lmx[i] = l.lmx[i] + r.lmx[i]; }
      if (r.len == r.rmx[i]) { ret.rmx[i] = l.rmx[i] + r.rmx[i]; }
      ret.mx[i] = std::max({l.mx[i], r.mx[i], l.rmx[i] + r.lmx[i]});
    }
  }
  return ret;
}

struct SegTree {
  std::vector<Info> t;
  std::vector<bool> lz;
  int n;

  void apply(const int p) {
    auto &x = t[p];
    std::swap(x.lc[0], x.lc[1]);
    std::swap(x.rc[0], x.rc[1]);
    std::swap(x.lmx[0], x.lmx[1]);
    std::swap(x.rmx[0], x.rmx[1]);
    std::swap(x.mx[0], x.mx[1]);
    lz[p] = !lz[p];
  }

  void pushdn(const int p) {
    if (lz[p]) {
      apply(p*2); apply(p*2+1);
      lz[p] = 0;
    }
  }

  void pushup(const int p) { t[p] = t[p*2] + t[p*2+1]; }

  void mod(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) { apply(p); return; }
    int m = (cl + cr) / 2;
    pushdn(p);
    if (l < m) { mod(l, r, cl, m, p*2); }
    if (r > m) { mod(l, r, m, cr, p*2+1); }
    pushup(p);
  }

  Info qry(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) { return t[p]; }
    int m = (cl+cr) / 2;
    pushdn(p);
    Info ret;
    if (l < m) { ret = ret + qry(l, r, cl, m, p*2);   }
    if (r > m) { ret = ret + qry(l, r, m, cr, p*2+1); }
    std::cout << l << " " << r << ": " << ret.len; NL;
    return ret;
  }

  SegTree(const std::vector<bool> &v) {
    n = v.size();
    t = std::vector<Info>(n*4);
    lz = std::vector<bool>(n*4);
    std::function<void(int, int, int)> build = [&](int l, int r, int p) -> void {
      if (l == r-1) { t[p] = { 1, {v[l], !v[l]}, {v[l], !v[l]}, {1, 1}, {1, 1}, {1, 1} }; return; }
      int m = (l+r)/2;
      build(l, m, p*2); build(m, r, p*2+1);
      pushup(p);
    };
    build(0, n, 1);
  }
};

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::string s; std::cin >> s;
  std::vector<bool> v;
  for(const auto c : s) {
    v.emplace_back((c == '1'));
  }
  SegTree seg(v);
  for(int i = 0; i < m; ++i) {
    int a, b, c; std::cin >> a >> b >> c;
    --b;
    if (a == 1) {
      std::cout << b << " " << c; NL;
      seg.mod(b, c, 0, v.size(), 1);
    } else {
      std::cout << b << " " << c; NL;
      auto ret = seg.qry(b, c, 0, v.size(), 1);
      std::cout << ret.mx[0]; NL;
    }
  }

  return 0;
}
