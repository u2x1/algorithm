#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

const double eps = 1e-8;

int sgn(double x) { return x < -eps ? -1 : x > eps; }

struct Line {
  double k, b;
  double operator()(int x) {
    return k * x + b;
  }
};

std::vector<Line> ls;

bool cmp(int l, int r, int x) {
  double y1 = ls[l](x), y2 = ls[r](x);
  if (sgn(y1 - y2) == 0) { return l > r; }
  return sgn(y1 - y2) < 0;
}


struct SegTree {
  std::vector<int> t;
  int n;

  SegTree(int n) : t(n*4), n(n) { }

  void apply(int x, int cl, int cr, int p) {
    int mid = cl + ((cr - cl) >> 1), &g = t[p];
    if (!g) { g = x; return; }
    if (cmp(g, x, mid)) { std::swap(g, x); }
    if (cmp(g, x, cl)) { apply(x, cl, mid, p*2); }
    if (cmp(g, x, cr-1)) { apply(x, mid, cr, p*2|1); }
  }

  void upd(int x, int l, int r, int cl, int cr, int p) { 
    if (l <= cl && cr <= r) { apply(x, cl, cr, p); return; }
    int mid = cl + ((cr - cl) >> 1);
    if (l < mid) { upd(x, l, r, cl, mid, p*2); }
    if (r > mid) { upd(x, l, r, mid, cr, p*2|1); }
  }

  int qry(int x, int cl, int cr, int p) {
    if (cl == x && cr == x + 1) { return t[p]; }
    int alter = 0;
    int mid = cl + ((cr - cl) >> 1);
    if (x < mid) { alter = qry(x, cl, mid, p*2); }
    if (x >= mid) { alter = qry(x, mid, cr, p*2|1); }
    return alter == 0 || cmp(alter, t[p], x) ? t[p] : alter; 
  }

  void upd(int x, int l, int r) { upd(x, l, r, 0, n, 1); }
  int qry(int x) { return qry(x, 0, n, 1); }
  
};

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  int lastans = 0;
  SegTree segTree(5e4);
  ls.push_back({0, 0});
  while (n--) {
    int o; std::cin >> o;
    if (o) {
      int x0, y0, x1, y1; std::cin >> x0 >> y0 >> x1 >> y1;
      x0 = (x0 + lastans - 1) % 39989 + 1;
      x1 = (x1 + lastans - 1) % 39989 + 1;
      y0 = (y0 + lastans - 1) % (int)1e9 + 1;
      y1 = (y1 + lastans - 1) % (int)1e9 + 1;
      if (x1 < x0) { std::swap(x0, x1); std::swap(y0, y1); }
      double k = x1 == x0 ? 0 : 1. * (y1 - y0) / (x1 - x0);
      double b = x1 == x0 ? std::max(y0, y1) : y0 - k * x0;
      ls.push_back({k, b});
      segTree.upd(ls.size()-1, x0, x1+1);
    } else {
      int k; std::cin >> k;
      int x = (k + lastans - 1) % 39989 + 1;
      lastans = segTree.qry(x);
      std::cout << lastans; NL;
    }
  }

  return 0;
}
