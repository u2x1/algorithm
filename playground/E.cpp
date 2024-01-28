#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

struct SegTree {
  std::vector<int> t, c, lz;
  std::vector<int> sum;
  int n;

  void apply(int p, int x) {
    t[p] += x; lz[p] += x;
  }

  void mod(int color, int x, int l, int r, int cl, int cr, int p) {
    if (color == c[p]) { apply(p, -x); return; }
    if (~color && color != c[p]) { return; }
    int m = (l+r) / 2;
    if 
  }

  SegTree(const auto& v) {
    n = v.size();
    lz = t = std::vector<int>(n*4);
    c = std::vector<int>(n*4, -1);
    sum = std::vector<int>(n+1);
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (l == r-1) { t[p] = v[l]; return; }
      int m = (l+r) / 2;
      build(l, m, p*2); build(m, r, p*2+1);
    };
  }
};

signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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
            seg.mod(b, c, 0, v.size(), 1);
        } else {
            auto ret = seg.qry(b, c, 0, v.size(), 1);
            std::cout << ret.mx[0]; NL;
        }
    }

    return 0;
}
