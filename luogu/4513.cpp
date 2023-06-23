#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 5e5+5;
int arr[maxN];

int N;

struct Node { int sum, maxl, maxr, maxv; } t[maxN*4];

void pushup(int p) {
  auto &tl = t[p*2], &tr = t[p*2+1];
  t[p] = {
      tl.sum + tr.sum
    , std::max(tl.maxl, tl.sum+tr.maxl)
    , std::max(tr.maxr, tr.sum+tl.maxr)
    , std::max({tl.maxv, tr.maxv, tl.maxr+tr.maxl})
  };
}

void build(int l = 1, int r = N, int p = 1) {
  if (l == r) { t[p] = { arr[l], arr[l], arr[l], arr[l] }; return; }
  int m = (l+r) / 2;
  build(l, m, p*2); build(m+1, r, p*2+1);
  pushup(p);
}

void update(int pos, int val, int l = 1, int r = N, int p = 1) {
  if (pos == l && pos == r) { t[p] = { val, val, val, val }; return; }
  int m = (l+r) / 2;
  if (pos <= m) { update(pos, val, l, m, p*2); }
  if (pos >  m) { update(pos, val, m+1, r, p*2+1); }
  pushup(p);
}

Node ask(int l, int r, int cl = 1, int cr = N, int p = 1) {
  if(l <= cl && cr <= r) { return t[p]; }
  int m = (cl+cr) / 2;
  if (l <= m && r > m) {
    Node tl = ask(l, r, cl, m, p*2), tr = ask(l, r, m+1, cr, p*2+1);
    Node ret = {
        tl.sum + tr.sum
      , std::max(tl.maxl, tl.sum+tr.maxl)
      , std::max(tr.maxr, tr.sum+tl.maxr)
      , std::max({tl.maxv, tr.maxv, tl.maxr+tr.maxl})
      };
    return ret;
  }
  if (l <= m) { return ask(l, r, cl, m, p*2); }
  else { return ask(l, r, m+1, cr, p*2+1); }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int M; std::cin >> N >> M;
  orep(i, 1, N+1) { std::cin >> arr[i]; }
  build();
  while(M--) {
    int e, a, b; std::cin >> e >> a >> b;
    if (e == 1) {
      if (a > b) { std::swap(a, b); }
      std::cout << ask(a, b).maxv; NL;
    } else {
      update(a, b);
    }
  }

  return 0;
}
