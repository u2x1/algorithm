#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <string>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';
#define int long long

using namespace std;

struct Node {
  int l, r, val; 
};
Node operator+(Node a, Node b) { return { a.l, b.r, a.val + b.val }; }

struct SegTree {
  std::vector<Node> t; std::vector<int> tg;
  int n;

  void pushup(int p) { t[p] = t[p*2] + t[p*2+1]; }

  void apply(int p, int val) {
    t[p].val += val * (t[p].r-t[p].l); tg[p] += val;
  }

  void pushdn(int p) {
    apply(p*2, tg[p]);
    apply(p*2+1, tg[p]);
    tg[p] = 0;
  }

  void _mod(int val, int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) { apply(p, val); return; }
    pushdn(p);
    int m = cl + (cr-cl) / 2;
    if (l < m)  { _mod(val, l, r, cl, m, p*2); }
    if (r > m) { _mod(val, l, r, m, cr, p*2|1); }
    pushup(p);
  }

  void mod(int val, int l, int r) { _mod(val, l, r, 0, n, 1); }

  int _sum(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) { return t[p].val; }
    pushdn(p);
    int ret = 0;
    int m = cl + (cr-cl) / 2;
    if (l < m)  { ret += _sum(l, r, cl, m, p*2); }
    if (r > m) { ret += _sum(l, r, m, cr, p*2|1); }
    return ret;
  }

  int sum(int l, int r) { return _sum(l, r, 0, n, 1); }
  
  SegTree(std::vector<int> &arr) {
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      t[p] = { l, r, 0 };
      if (l == r-1) { t[p].val = arr[l]; return; }
      int m = l + (r-l) / 2;
      build(l, m, p*2); build(m, r, p*2+1);
      pushup(p);
    };
    n = arr.size();
    tg = std::vector<int>(n*4);
    t = std::vector<Node>(n*4);
    build(0, n, 1);
  }

  void debug() {
    for(auto [l, r, val] : t) { std::cout << l << " " << r << " " << val; NL; }
  }

};


signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
    std::vector<int> v(n);
    orep(i, 0, n) { std::cin >> v[i]; }
    SegTree t(v);
  while(m--) {
    // orep(i, 0, n) { std::cout << t.sum(i, i+1) << " "; } NL;
    // NL;
    // t.debug();
    // NL;
    int e; std::cin >> e;
    if (e == 1) {
      int x, y, z; std::cin >> x >> y >> z;
      t.mod(z, x-1, y);
    } else {
      int x, y; std::cin >> x >> y;
      std::cout << t.sum(x-1, y); NL;
    }
  }

  return 0;
}
