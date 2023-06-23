#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
int N, M;

int cnt;

struct Node { int val, l, r; } t[maxN*20];

int build(int l = 1, int r = N) {
  int u = ++cnt;
  if (l == r) { std::cin >> t[u].val; return u; }
  int m = (l + r) / 2;
  t[u] = { 0, build(l, m), build(m+1, r) };
  return u;
}

int update(int pos, int val, int p, int cl = 1, int cr = N) {
  int u = ++cnt;
  if (pos == cl && pos == cr) { t[u] = { val, 0, 0 }; return u; }
  t[u] = { 0, t[p].l, t[p].r };
  int m = (cl+cr) / 2;
  if (pos <= m) { t[u].l = update(pos, val, t[p].l, cl, m); }
  else { t[u].r = update(pos, val, t[p].r, m+1, cr); }
  return u;
}

int ask(int pos, int p, int cl = 1, int cr = N) {
  if (cl == cr && cl == pos) { return t[p].val; }
  int m = (cl + cr) / 2;
  if (pos <= m) { return ask(pos, t[p].l, cl, m); }
  else { return ask(pos, t[p].r, m+1, cr); }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N >> M;
  build();
  std::vector<int> root(M+1);
  root[0] = 1;
  orep(i, 1, M+1) {
    int v, e, pos; std::cin >> v >> e >> pos;
    if (e == 1) {
      int val; std::cin >> val;
      root[i] = update(pos, val, root[v]);
    } else {
      std::cout << ask(pos, root[v]); NL;
      root[i] = root[v];
    }
  }

  return 0;
}
