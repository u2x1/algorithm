#include <iostream>
#include <vector>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e5+5;
int a[maxN];
std::vector<int> v;
int idx(int x) { return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
int N, M;

struct Node { int val, l, r; } t[maxN*4*20];
int cnt;

int build(int l = 1, int r = v.size()) {
  int u = ++cnt;
  if (l != r) {
    int m = l + ((r-l) >> 1);
    t[u] = { 0, build(l, m), build(m+1, r) };
  }
  return u;
}

void pushup(int p) { t[p].val = t[t[p].l].val + t[t[p].r].val; }

int update(int pos, int p, int cl = 1, int cr = v.size()) {
  int u = ++cnt;
  t[u] = t[p];
  if (pos == cl && pos == cr) { ++t[u].val; return u; }
  int m = cl + ((cr-cl)>>1);
  if (pos <= m) { t[u].l = update(pos, t[p].l, cl, m); }
  else { t[u].r = update(pos, t[p].r, m+1, cr); }
  pushup(u);
  return u;
}

int root[maxN*4*20];

std::vector<int> son[maxN];
int dfn[maxN];
int st[maxN][20]; int tot; int _fa[maxN];

int ask(int k, int uu, int vv, int lca, int lcafa, int cl = 1, int cr = v.size()) {
  if (cl == cr) { return v[cl-1]; }
  int m = cl + ((cr-cl) >> 1);
  int lcnt = t[t[uu].l].val + t[t[vv].l].val - t[t[lca].l].val - t[t[lcafa].l].val;
//  std::cout << lcnt << " ";
  if (lcnt >= k) { return ask(k, t[uu].l, t[vv].l, t[lca].l, t[lcafa].l, cl, m); }
  else { return ask(k-lcnt, t[uu].r, t[vv].r, t[lca].r, t[lcafa].r, m+1, cr); }
}


void dfs(int u = 1, int fa = 0) {
  st[tot][0] = fa; dfn[u] = ++tot; _fa[u] = fa;
  root[u] = update(idx(a[u]), root[fa]);
  for(auto &x : son[u]) {
    if (fa != x) { dfs(x, u); }
  }
}

int dfnmin(int x, int y) { return dfn[x] < dfn[y] ? x : y; }
void init() {
  orep(k, 1, 20) {
    for(int i = 0; i + (1<<k)-1 <= tot; ++i) {
      st[i][k] = dfnmin(st[i][k-1], st[i+(1<<(k-1))][k-1]);
    }
  }
}

int lca(int u, int v) {
  if (u == v) { return u; }
  if (dfn[u] > dfn[v]) { std::swap(u, v); }
  int k = std::__lg(dfn[v]-dfn[u]);
  return dfnmin(st[dfn[u]][k], st[dfn[v]-(1<<k)][k]);
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N >> M;
  orep(i, 1, N+1) { std::cin >> a[i]; }
  std::set<int> _(a+1, a+1+N);
  v = std::vector<int>(_.begin(), _.end());
  orep(i, 1, N) {
    int u, v; std::cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  dfs(); init();
  int last = 0;
  orep(i, 0, M) {
    int u, v, k; std::cin >> u >> v >> k;
    u ^= last;
//    std::cout << "u: " << u << " v: " << v;
//    std::cout << " lca: " << lca(u, v); NL;
    last = ask(k, root[u], root[v], root[lca(u, v)], root[_fa[lca(u, v)]]);
    std::cout << last; NL;
    
  }

  return 0;
}
