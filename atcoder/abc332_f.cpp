#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;
const int mo = 998244353;

struct SegTree {
  std::vector<lnt> t, f1, f2;
  int n;

  SegTree (const std::vector<int> &v) {
    n = v.size();
    t.assign(4*n, 0ll);
    f1.assign(4*n, 1ll);
    f2.assign(4*n, 0ll);
    auto build = [&](auto &&self, int l, int r, int p) {
      if (l == r - 1) { t[p] = v[l]; return; }
      int mid = l + ((r - l) >> 1);
      self(self, l, mid, p*2); 
      self(self, mid, r, p*2+1); 
    };
    build(build, 0, n, 1);
  }

  inline void apply(int p, int a, int b) {
    t[p] = (a * t[p] % mo + b) % mo;
    f1[p] = f1[p] * a % mo;
    f2[p] = (f2[p] * a % mo + b) % mo;
  }

  void pushdn(int p) {
    apply(p*2, f1[p], f2[p]);
    apply(p*2+1, f1[p], f2[p]);
    f1[p] = 1; f2[p] = 0;
  }

  void upd(int l, int r, int a, int b, int cl, int cr, int p) {
    if (l <= cl && cr <= r) { apply(p, a, b); return; }
    int mid = cl + ((cr - cl) >> 1);
    pushdn(p);
    if (l < mid) { upd(l, r, a, b, cl, mid, p*2); }
    if (r > mid) { upd(l, r, a, b, mid, cr, p*2+1); }
  }

  void upd(int l, int r, int a, int b) {
    if (r <= l) { return; }
    upd(l, r, a, b, 0, n, 1);
  }

  int ask(int pos, int cl, int cr, int p) {
    if (pos == cl && pos == cr - 1) { return t[p]; }
    int mid = cl + ((cr - cl) >> 1);
    pushdn(p);
    if (pos < mid) { return ask(pos, cl, mid, p*2); }
    else { return ask(pos, mid, cr, p*2+1); }
  }

  int ask(int pos) { return ask(pos, 0, n, 1); }
};

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  SegTree segTree(v);
  auto ksm = [&](lnt x, int e) {
    lnt ret = 1;
    while (e) {
      if (e & 1) { ret = ret * x % mo; }
      x = x * x % mo; e >>= 1;
    }
    return ret;
  };
  auto inv = [&](int x) {
    return ksm(x, mo-2);
  };
  for (int i = 0; i < m; ++i) {
    int l, r, x; std::cin >> l >> r >> x; --l;
    int len = r - l;
    lnt d = inv(len);
    segTree.upd(l, r, (len - 1) * d % mo, x * d % mo);
  }
  for (int i = 0; i < n; ++i) {
    std::cout << segTree.ask(i) << " ";
  }
  

  return 0;
}
