#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct SegTree {
  std::vector<int> t;
  int n;
  SegTree (int nn) : t(nn*2), n(nn) {}

  void mod(int pos, int x, int cl, int cr, int p) {
    if (pos == cl && pos == cr - 1) { t[p] = x; return; }
    int mid = cl + ((cr - cl) >> 1);
    if (pos < mid) { mod(pos, x, cl, mid, mid * 2); }
    else { mod(pos, x, mid, cr, mid * 2 + 1); }
    t[p] = std::max(t[mid*2], t[mid*2+1]);
  }

  int ask(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) { return t[p]; }
    int mid = cl + ((cr - cl) >> 1);
    if (r <= mid) { return ask(l, r, cl, mid, mid * 2); }
    if (l >= mid) { return ask(l, r, mid, cr, mid * 2 + 1); }
    return std::max(ask(l, r, cl, mid, mid * 2), ask(l, r, mid, cr, mid * 2 + 1));
  }

  int ask(int l, int r) { return ask(l, r, 0, n, 1); }
  void mod(int pos, int x) { return mod(pos, x, 0, n, 1); }
};

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, d; std::cin >> n >> d;
  const int maxN = 5e5+1;
  SegTree segTree(maxN);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    int x; std::cin >> x;
    int l = std::max(0, x - d), r = std::min(maxN, x + d + 1);
    int cur = segTree.ask(l, r) + 1;
    segTree.mod(x, cur);
    ret = std::max(ret, cur);
  }
  std::cout << ret;

  return 0;
}
