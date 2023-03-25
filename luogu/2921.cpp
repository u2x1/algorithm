#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int nxt[maxN];
int color[maxN], dfn[maxN];
int cycle[maxN];
int intime[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1) {
    std::cin >> nxt[i];
  }
  orep(i, 1, n+1) {
    if (color[i]) { continue; }
    int j, t;
    for(j = i, t = 1; !color[j]; j=nxt[j], ++t) {
      color[j] = i; dfn[j] = t;
      const int nex = nxt[j];
      if (color[nex] == i) {
        cycle[i] = dfn[j]-dfn[nex]+1;
        intime[i] = dfn[nex];
      } else {
        const int c = color[nex];
        cycle[i] = cycle[c];
        if (dfn[nex] >= intime[c]) {
          intime[i] = t + 1;
        } else {
          intime[i] = t + 1 + intime[c] - dfn[nex];
        }
      }
    }
  }

  orep(i, 1, n+1) {
    if (dfn[i] >= intime[color[i]]) {
      std::cout << cycle[color[i]];
    } else {
      std::cout << cycle[color[i]] + intime[color[i]] - dfn[i];
    }
    NL;
  }

  return 0;
}
