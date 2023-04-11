#include <iostream>
#include <vector>

#define orep(i, a, b) for(int i = (a); i < (b); ++i)
#define NL std::cout << '\n'

const int maxN = 1e5+5;
struct st{
  int v, w;
};
std::vector<st> son[maxN];

int fa[maxN][20], dis[maxN][20];
int dep[maxN];
void init(const int u = 1, const int faa = 0, const int w = 0) {
  fa[u][0] = faa; dis[u][0] = w; dep[u] = dep[faa] + 1;
  orep(i, 1, 20) {
    fa[u][i] = fa[fa[u][i-1]][i-1];
    dis[u][i] = dis[u][i-1] + dis[fa[u][i-1]][i-1];
  }
  for(auto x : son[u]) {
    if (x.v == faa) {
      continue;
    }
    init(x.v, u, x.w);
  }
}

int lg[maxN];

int lca(int u, int v) {
  if (dep[u] > dep[v]) {
    std::swap(u, v);
  }
  while(dep[v] > dep[u]) {
    v = fa[v][lg[dep[v]-dep[u]]];
  }
  if (v == u) {
    return v;
  }
  while(fa[v][0] != fa[u][0]) {
    int i = 1;
    while(fa[v][i] != fa[u][i]) {
      ++i;
    }
    v = fa[v][i-1]; u = fa[u][i-1];
  }
  return fa[v][0];
}

long long caldis(int u, int v) {
  const int a = lca(u, v);
  long long ret = 0;
  while(u != a) {
    ret += dis[u][lg[dep[u]-dep[a]]];
    u = fa[u][lg[dep[u]-dep[a]]];
  }
  while(v != a) {
    ret += dis[v][lg[dep[v]-dep[a]]];
    v = fa[v][lg[dep[v]-dep[a]]];
  }
  return ret;
}

int route[maxN];
long long memo[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 2, maxN) {
    lg[i] = lg[i>>1] + 1;
  }
  int n, k; std::cin >> n >> k;
  if (k == 2) {
    std::cout << "0 0"; return 0;
  }
  orep(i, 1, n) {
    int a, b, t; std::cin >> a >> b >> t;
    son[a].push_back({b, t});
    son[b].push_back({a, t});
  }
  orep(i, 1, k+1) {
    std::cin >> route[i];
  }
  init();
  long long raw = 0;
  orep(i, 2, k+1) {
    memo[i-1] = caldis(route[i-1], route[i]);
    // std::cout << "dis " << route[i-1] << "-" << route[i] << " is " << memo[i-1]; NL;
    raw += memo[i-1];
  }
  std::cout << raw - memo[1];
  orep(i, 2, k) {
    std::cout << " " << raw-memo[i-1]-memo[i]+caldis(route[i-1], route[i+1]);
  }
  std::cout << " " << raw-memo[k-1];
	return 0;
}
