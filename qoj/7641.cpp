#include "bits/stdc++.h"

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int o = 1;
constexpr int maxN = 5e6;

struct Node { int l, r, v; } t[maxN];
int f[maxN];

struct SegTree {

  int root, n;

  SegTree(int n) : root(o++), n(n) { }

  void pushup(int p) { t[p].v = t[t[p].l].v + t[t[p].r].v; }

  inline void apply(int &p, int x) {
    if (!p) { p = o++; }
    t[p].v += x; f[p] += x;
  }

  void pushdn(int p) {
    apply(t[p].l, f[p]);
    apply(t[p].r, f[p]);
    f[p] = 0;
  }

  void upd(int x, int l, int r, int cl, int cr, int &p) {
    if (l == r) { return; }
    if (!p) { p = o++; }
    if (l <= cl && cr <= r) { apply(p, x); return; }
    int mid = cl + ((cr - cl) >> 1);
    pushdn(p);
    if (l < mid) { upd(x, l, r, cl, mid, t[p].l); }
    if (r > mid) { upd(x, l, r, mid, cr, t[p].r); }
    if (t[p].r || t[p].l) { pushup(p); }
  }

  int qry(int l, int r, int cl, int cr, int &p) {
    if (l == r) { return 0; }
    if (!p) { p = o++; }
    if (l <= cl && cr <= r) { return t[p].v; }
    int mid = cl + ((cr - cl) >> 1);
    pushdn(p);
    if (l >= mid) { return qry(l, r, mid, cr, t[p].r); }
    if (r <= mid) { return qry(l, r, cl, mid, t[p].l); }
    return qry(l, r, mid, cr, t[p].r) + qry(l, r, cl, mid, t[p].l);
  }

};

// struct BIT {
//   std::vector<lnt> v; int n;
//   BIT (int nn) : v(nn) , n(nn) {}
//   void add(int p, int x) {
//     for (++p; p <= n; p += p & -p) {
//       v[p-1] += x;
//     }
//   }
//   lnt qry(int p) {
//     lnt ret = 0;
//     for (; p > 0; p -= p & -p) {
//       ret += v[p-1];
//     }
//     return ret;
//   }
// };

struct Node_t {
  int l, r; mutable int v;
  bool operator< (const Node_t& x) const { return l < x.l; }
};

struct ODT {
  std::set<Node_t> st;

  auto split(int x) {
    auto it = std::prev(st.upper_bound({x}));
    if (it->l == x) { return it; }
    auto [l, r, v] = *it;
    st.erase(it);
    st.insert({l, x, v});
    return st.insert({x, r, v}).first;
  }

  void assign(int l, int r, int v) {
    auto itr = split(r), itl = split(l);
    st.erase(itl, itr);
    st.insert({l, r, v});
  }
};

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);

  int n, q; std::cin >> n >> q;

  SegTree segTree(n);
  std::vector<ODT> odt(q);
  for (int i = 0; i < q; ++i) { odt[i].st.insert({0, n, 0}); }

  while (q--) {
    std::string s; std::cin >> s;
    if (s == "?") {
      int pos; std::cin >> pos; --pos;
      std::cout << segTree.qry(pos, pos+1, 0, n, segTree.root) << std::endl;
    } else if (s == "+") {
      int l, r, v; std::cin >> l >> r >> v; --v, --l;
      for (auto itr = odt[v].split(r), itl = odt[v].split(l); itl != itr; ++itl) {
        if (itl->v == 0) { segTree.upd(1, itl->l, itl->r, 0, n, segTree.root); }
      }
      odt[v].assign(l, r, 1);
      // for (auto [l, r, v] : odt[v].st) { std::cout << l << ',' << r << ',' << v << " "; } NL;
    } else {
      int l, r, v; std::cin >> l >> r >> v; --v, --l;
      for (auto itr = odt[v].split(r), itl = odt[v].split(l); itl != itr; ++itl) {
        if (itl->v == 1) { segTree.upd(-1, itl->l, itl->r, 0, n, segTree.root); }
      }
      odt[v].assign(l, r, 0);
      // for (auto [l, r, v] : odt[v].st) { std::cout << l << ',' << r << ',' << v << " "; } NL;
    }
  }

  return 0;
}
