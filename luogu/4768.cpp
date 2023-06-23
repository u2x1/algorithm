#include <iostream>
#include <functional>
#include <cstring>
#include <algorithm>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 8e5+5;

long long dis[maxN];
struct WRAP { int v; };
bool operator<(const WRAP &a, const WRAP &b) { return dis[a.v] > dis[b.v]; }
struct edge { int u, v, l, a; };

void dij(std::vector<edge> &eg, int &n) {
  memset(dis, 0x3f, sizeof(dis));
  std::vector<std::vector<std::pair<int, int>>> son(n+1);
  for(edge &e : eg) {
    son[e.u].push_back({e.v, e.l});
    son[e.v].push_back({e.u, e.l});
  }
  std::priority_queue<WRAP> q;
  dis[1] = 0; q.push({1});
  while(q.size()) {
    int u = q.top().v; q.pop();
    for(auto [v, l] : son[u]) {
      if (dis[v] > dis[u] + l) {
        dis[v] = dis[u] + l; q.push({v});
      }
    }
  }
}

int val[maxN];
int _fa[maxN][25];
std::vector<std::vector<int>> kruskal(std::vector<edge> &eg, int n, int &root) {
  std::vector<int> fa(n*2+1); orep(i, 1, n*2+1) { fa[i] = i; }
  std::function<int(int)> find = [&](const int x)
      { return x == fa[x] ? x : fa[x] = find(fa[x]); };
  std::sort(eg.begin(), eg.end(), [](const edge &lhs, const edge &rhs)
      { return lhs.a > rhs.a; });
  int cur = n+1;
  std::vector<std::vector<int>> ret(n*2+1);
  for (auto [u, v, _, a] : eg) {
    if (find(u) == find(v)) { continue; }
    // std::cout << "merging " << u << " " << v << " at " << cur ; NL;
    ret[cur].emplace_back(find(u));
    ret[cur].emplace_back(find(v));
    // std::cout << find(u) << " " << find(v) << " ";
    dis[cur] = std::min(dis[find(u)], dis[find(v)]);
    _fa[find(u)][0] = _fa[find(v)][0] = cur;
    fa[find(u)] = fa[find(v)] = cur;
    val[cur] = a;
    ++cur;
  }
  root = cur-1;
  return ret;
}

void initFa(int n) {
  orep(k, 1, 25) {
    orep(i, 1, n+1) {
      _fa[i][k] = _fa[_fa[i][k-1]][k-1];
    }
  }
}

int dep[maxN];
std::vector<std::vector<int>> son;
void dfs(int u, int fa) {
  // dep[u] = dep[fa] + 1;
  // for(auto &v : son[u]) { dfs(v, u); }
  std::queue<std::pair<int, int>> q;
  q.push({u, fa});
  while(q.size()) {
    auto x = q.front(); q.pop();
    dep[x.first] = dep[x.second] + 1;
    for(auto &v : son[x.first]) { q.push({v, x.first}); }
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) { std::swap(u, v); }
  while(dep[u] > dep[v]) {
    int k = std::__lg(dep[u]-dep[v]);
    u = _fa[u][k];
  }
  if (u == v) { return u; }
  while(_fa[u][0] != _fa[v][0]) {
    int k = 1;
    while(_fa[u][k] != _fa[v][k]) { ++k; }
    u = _fa[u][k-1];
    v = _fa[v][k-1];
  }
  return _fa[u][0];
}

void solve() {
  int n, m; std::cin >> n >> m;
  std::vector<edge> eg(m);
  orep(i, 0, m) { std::cin >> eg[i].u >> eg[i].v >> eg[i].l >> eg[i].a; }

  dij(eg, n);
  int root; son = kruskal(eg, n, root);
  dfs(root, 0);
  initFa(root);

  long long Q, K, S; std::cin >> Q >> K >> S;
  long long lastans = 0;
  orep(i, 0, Q) {
    long long v0, p0; std::cin >> v0 >> p0;
    long long v = (v0+K*lastans-1) % n + 1;
    long long p = (p0+K*lastans) % (S + 1);
    int ca = lca(1, v);
    if (v == 1 || val[ca] > p) { lastans = 0; }
    else {
      int u = v;
      while(dep[_fa[u][0]] > dep[ca] && val[_fa[u][0]] > p) {
        int k = 0;
        while(_fa[u][k+1] && dep[_fa[u][k+1]] >= dep[ca] && val[_fa[u][k+1]] > p) { ++k; }
        u = _fa[u][k];
      }
      lastans = dis[u];
    }
    std::cout << lastans; NL;
  }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t = 0; std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
