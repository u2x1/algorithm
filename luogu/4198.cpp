#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e5+5;
int arr[maxN];

struct Node { double k; int v; } t[maxN*4];
int N, M;

int get(int p, double x, int l, int r) {
  if (t[p].k <= x) { return 0; }
  if (l == r) { return t[p].k > x; }
  if (t[p*2].k <= x) { return get(p*2+1, x, (l+r)/2+1, r); }
  return get(p*2, x, l, (l+r)/2) + t[p].v - t[p*2].v;
}

Node combine(int l, int r, int cl, int cr) {
  int rv = get(r, t[l].k, (cl+cr)/2+1, cr);
  return { std::max(t[l].k, t[r].k), t[l].v + rv };
}

void pushup(int p, int cl, int cr) { t[p] = combine(p*2, p*2+1, cl, cr); }

void update(int pos, double val, int cl = 1, int cr = N, int p = 1) {
  if (pos == cl && pos == cr) { t[p] = { val, 1 }; return; }
  int m = (cl+cr) / 2;
  if (pos <= m) { update(pos, val, cl, m, p*2); }
  if (pos >  m) { update(pos, val, m+1, cr, p*2+1); }
  pushup(p, cl, cr);
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N >> M;
  while(M--) {
    int x, y; std::cin >> x >> y;
    update(x, 1.0*y/x);
    std::cout << t[1].v; NL;
  }

  return 0;
}
