#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
std::vector<int> son[maxN];
int fa[maxN][20];
int in[maxN];
int dep[maxN];

void init(const int u, const int faa = 0) {
  dep[u] = dep[faa]+1; fa[u][0] = faa;
  orep(i, 1, 20) {
    fa[u][i] = fa[fa[u][i-1]][i-1];
  }
  for(const int v : son[u]) { init(v, u); }
}

int lg[maxN];
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n) {
    int a, b; std::cin >> a >> b;
    son[a].emplace_back(b);
    in[b]++;
  }
  int root = 0;
  orep(i, 1, n+1) { if (!in[i]) { root = i; } }
  init(root);
  int q; std::cin >> q;
  
  orep(i, 2, maxN) { lg[i] = lg[i>>1] + 1; }
  orep(i, 0, q) {
    int x, y; std::cin >> x >> y;
    if (dep[x] > dep[y]) { std::cout << "No"; NL; continue; }
    while(dep[y] > dep[x]) {
      y = fa[y][lg[dep[y]-dep[x]]];
    }
    if (y == x) { std::cout << "Yes"; NL; continue; }
    std::cout << "No"; NL;
  }

  return 0;
}
