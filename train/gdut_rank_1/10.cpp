#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e2+5;
int oppo[maxN][maxN];
int fa[maxN];

int find(int u) {
  if (u == fa[u]) { return u; }
  return (fa[u] = find(fa[u]));
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k; std::cin >> n >> m >> k;
  orep(i, 1, n+1) { fa[i] = i; }
  orep(i, 0, m) {
    int a, b, c; std::cin >> a >> b >> c;
    if (c==-1) { oppo[a][b] = oppo[b][a] = 1; }
    else {
      fa[find(a)] = find(b);
    }
  }
  orep(i, 0, k) {
    int a, b; std::cin >> a>>b;
    if (oppo[a][b]) {
      if (find(a) == find(b)) {
        std::cout << "OK but..."; NL; continue;
      } else {
        std::cout << "No way"; NL; continue;
      }
    } else if (find(a) == find(b)){
      std::cout << "No problem"; NL; continue;
    } else {
      std::cout << "OK"; NL; continue;
    }
  }

  return 0;
}
