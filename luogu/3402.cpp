#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 3e5+5;
int a[maxN];
int N, M;

struct Node { int fa, siz, l, r; } t[maxN*4*20];
int cnt;

int build(int l = 1, int r = N) {
  int u = ++cnt;
  if (l == r) { t[u] = { l, 1, 0, 0 }; return u; }
  int m = l + ((r-l) >> 1);
  t[u] = { 0, 0, build(l, m), build(m+1, r) };
  return u;
}

Node& ask(int pos, int p, int cl = 1, int cr = N) {
  if (cl == cr) { return t[p]; }
  int m = cl + ((cr-cl) >> 1);
  if (pos <= m) { return ask(pos, t[p].l, cl, m); }
  else { return ask(pos, t[p].r, m+1, cr); }
}

int update(int pos, int fa, int sz, int p, int cl = 1, int cr = N) {
  int u = ++cnt;
  if (cl == cr) { t[u] = { fa, sz, 0, 0}; return u; }
  int m = cl + ((cr-cl) >> 1);
  if (pos <= m) { t[u].l = update(pos, fa, sz, t[p].l, cl, m); }
  else { t[u].r = update(pos, fa, sz, t[p].r, m+1, cr); }
  return u;
}

std::pair<int, int> find(int u, int p) {
  for(int dis = 0; ;++dis) {
    auto [x, sz, _, __] = ask(u, p);
    if (x == u) { return {x, dis}; }
    else { u = x; }
  }
}

int root[maxN];
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N >> M;
  build();
  root[0] = 1;
  orep(i, 1, M+1) {
    root[i] = root[i-1];
    int e; std::cin >> e;
    if (e == 1) {
      int u, v; std::cin >> u >> v;
      auto [fu, du] = find(u, root[i]);
      auto [fv, dv] = find(v, root[i]);
      if (fu == fv) { continue; }
    } else if (e == 2) {
      int k; std::cin >> k;
      root[i] = root[k];
    } else if (e == 3) {
      int a, b; std::cin >> a >> b;
      std::cout << (find(a, root[i]) == find(a, root[i]));
    }
  }

  return 0;
}
