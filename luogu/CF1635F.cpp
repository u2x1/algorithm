#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using i64 = long long;
const int maxN = 3e5+5, INF = 0x3f3f3f3f;
i64 xs[maxN];
i64 vals[maxN];
struct st { int l, r; } ps[maxN];
bool operator<(st &a, st &b) { return a.r < b.r; }

i64 t[maxN*4], tg[maxN*4];

int n;

void mark(int p, i64 val) { tg[p] = std::min(tg[p], val); }
void pushup(int p) { t[p] = std::min(t[p*2], t[p*2+1]); }
void pushdn(int p) { mark(p*2, tg[p]); mark(p*2+1, tg[p]); t[p] = std::min(t[p], tg[p]); tg[p] = tg[0]; }

i64 get(int pos, int cl = 1, int cr = n, int p = 1) {
  if (cl == pos && cr == pos) { return std::min(t[p], tg[p]); }
  pushdn(p);
  int mid = (cl+cr) >> 1;
  if (pos <= mid) { return get(pos, cl, mid, p*2); }
  else { return get(pos, mid+1, cr, p*2+1); }
};

void mod(i64 val, int l, int r, int cl = 1, int cr = n, int p = 1) {
  if (l <= cl && cr <= r) { mark(p, val); return; }
  pushdn(p);
  int mid = (cl+cr) >> 1;
  if (l <= mid) { mod(val, l, r, cl, mid, p*2); }
  if (mid < r) { mod(val, l, r, mid+1, cr, p*2+1); }
  pushup(p);
}

i64 ret[maxN];
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int m; std::cin >> n >> m;
  std::vector<std::pair<int, int>> stk; i64 tmp;
  orep(i, 1, n+1) {
    std::cin >> xs[i]; std::cin >> tmp; vals[i] = tmp;
    ps[i].l = 1; ps[i].r = n;
    while(stk.size() && stk.back().first > tmp) { ps[stk.back().second].r = i; stk.pop_back(); }
    if (stk.size()) { ps[i].l = stk.back().second; }
    stk.push_back({tmp, i});
  }
  std::vector<st> rect;
  orep(i, 1, n+1) {
    if (ps[i].l != i) { rect.push_back({ps[i].l, i}); }
    if (ps[i].r != i) { rect.push_back({i, ps[i].r}); }
  }
  std::sort(rect.begin(), rect.end());
  memset(t, 0x3f, sizeof(t)); memset(tg, 0x3f, sizeof(tg));

  struct query { int l, r, idx; };
  const auto cmp = [](query &a, query &b) { return a.r < b.r; };

  std::vector<query> qs(m);
  orep(i, 0, m) { std::cin >> qs[i].l >> qs[i].r; qs[i].idx = i; }
  std::sort(qs.begin(), qs.end(), cmp);

  auto pos = 0ul;
  orep(i, 0ul, qs.size()) {
    while(pos != rect.size() && rect[pos].r <= qs[i].r) {
      mod((xs[rect[pos].r]-xs[rect[pos].l])*(vals[rect[pos].r]+vals[rect[pos].l]), 1, rect[pos].l);
//      std::cout << "mod " << 1 << "," << rect[pos].l << " to " << (xs[rect[pos].r]-xs[rect[pos].l])*(vals[rect[pos].r]+vals[rect[pos].l]); NL;
      ++pos;
    }
    ret[qs[i].idx] = get(qs[i].l);
//    std::cout << "get " << qs[i].l << " IS " << get(qs[i].l); NL;
  }
  orep(i, 0, m) { std::cout << ret[i]; NL; }
  return 0;
}
