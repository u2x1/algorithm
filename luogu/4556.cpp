#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct Node {
  int l = 0, r = 0;
  std::pair<int, int> v = {0, 0};
} t[5000010];

int o = 1;

void pushup(int p) { t[p].v = std::max(t[t[p].l].v, t[t[p].r].v); }


struct SegTree {
  int root, n;

  SegTree(int nn) : root(o++), n(nn) {}

  void upd(int x, int pos, int cl, int cr, int p) {
    if (cl == pos && cr == pos+1) { t[p].v.first += x; t[p].v.second = -pos; return; }
    int mid = cl + ((cr - cl) >> 1);
    if (pos < mid) {
      t[p].l = t[p].l ? t[p].l : o++;
      upd(x, pos, cl, mid, t[p].l);
    } else {
      t[p].r = t[p].r ? t[p].r : o++;
      upd(x, pos, mid, cr, t[p].r);
    }
    pushup(p);
  }

  int qry(int pos, int cl, int cr, int p) {
    if (cl == pos && cr == pos+1) { return t[p].v.first; }
    int mid = cl + ((cr - cl) >> 1);
    if (pos < mid) {
      if (!t[p].l) { return 0; };
      return qry(pos, cl, mid, t[p].l);
    } else {
      if (!t[p].r) { return 0; };
      return qry(pos, mid, cr, t[p].r);
    }
  }
};

void merge(int a, int b) {
  if (!t[a].l) { t[a].l = t[b].l; }
  else if (t[b].l) {
    t[t[a].l].v.first += t[t[b].l].v.first;
    merge(t[a].l, t[b].l);
  }
  if (!t[a].r) { t[a].r = t[b].r; }
  else if (t[b].r) {
    t[t[a].r].v.first += t[t[b].r].v.first;
    merge(t[a].r, t[b].r);
  }
  if (t[a].l || t[a].r) { pushup(a); }
}

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);

  // SegTree seg1(10), seg2(10);
  // for (int i = 0; i < 10; ++i) {
  //   seg1.upd(1, i, 0, 10, seg1.root);
  //   seg2.upd(1, i, 0, 10, seg2.root);
  // }
  // merge(seg1.root, seg2.root);
  // for (int i = 0; i < 10; ++i) {
  //   std::cout << seg1.qry(i, 0, 10, seg1.root) << " ";
  // } NL;

  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n-1; ++i) {
    int a, b; std::cin >> a >> b;
    adj[b-1].emplace_back(a-1);
    adj[a-1].emplace_back(b-1);
  }

  std::vector fa(n, std::vector<int>(21));
  std::vector<int> dep(n);
  auto dfs1 = [&](auto &&self, int u) -> void {
    for (int i = 1; i < 21; ++i) {
      fa[u][i] = fa[fa[u][i-1]][i-1];
    }
    for (auto x : adj[u]) {
      if (x == fa[u][0]) { continue; }
      dep[x] = dep[u] + 1;
      fa[x][0] = u;
      self(self, x);
    }
  };
  dfs1(dfs1, 0);

  auto lca = [&](int u, int v) {
    if (dep[u] > dep[v]) { std::swap(u, v); }
    for (int i = 20; i > -1; --i) {
      if (dep[v] - (1 << i) >= dep[u]) {
        v = fa[v][i];
      }
    }
    if (u == v) { return u; }
    for (int i = 20; i > -1; --i) {
      if (fa[u][i] == fa[v][i]) { continue; }
      u = fa[u][i]; v = fa[v][i];
    }
    return fa[u][0];
  };


  std::vector<SegTree> segs; segs.reserve(n);
  for (int i = 0; i < n; ++i) {
    segs.emplace_back(1e5+1);
  }

  for (int i = 0; i < m; ++i) {
    int a, b, c; std::cin >> a >> b >> c;
    --a, --b;
    int g = lca(a, b);
    // std::cout << "lca of " << a << ", " << b << " is " << g; NL;

    segs[a].upd(1, c, 0, 1e5+1, segs[a].root);
    segs[b].upd(1, c, 0, 1e5+1, segs[b].root);
    segs[g].upd(-1, c, 0, 1e5+1, segs[g].root);
    if (g) { segs[fa[g][0]].upd(-1, c, 0, 1e5+1, segs[fa[g][0]].root); }
      // std::cout << "after upd " << a << ": ";
      // for (int i = 2; i < 4; ++i) {
      //   std::cout << segs[a].qry(i, 0, 1e5, segs[a].root) << " ";
      // } NL;
  }

  auto dfs2 = [&](auto &&self, int u) -> void {
      // std::cout << "before mergeing " << u << ": ";
      // for (int i = 2; i < 4; ++i) {
      //   std::cout << segs[u].qry(i, 0, 1e5, segs[u].root) << " ";
      // } NL;
    for (auto x : adj[u]) {
      if (x == fa[u][0]) { continue; }
      self(self, x);
      merge(segs[u].root, segs[x].root);
      // std::cout << "after mergeing " << u << ", " << x << ": ";
      // for (int i = 2; i < 4; ++i) {
      //   std::cout << segs[u].qry(i, 0, 1e5, segs[u].root) << " ";
      // } NL;
    }
  };
  dfs2(dfs2, 0);

  for (int i = 0; i < n; ++i) {
    std::cout << -t[segs[i].root].v.second; NL;
  }

  return 0;
}
