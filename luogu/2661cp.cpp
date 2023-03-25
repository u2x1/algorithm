#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int nxt[maxN];

int color[maxN], dfn[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1) {
    std::cin >> nxt[i];
  }
  int ret = 0x3f3f3f3f;
  orep(i, 1, n+1) {
    if (color[i]) { continue; }
    int j; int t = 1;
    for(j = i; !color[j]; j = nxt[j], ++t) {
      color[j] = i;
      dfn[j] = t;
      if (color[nxt[j]] == i) {
        ret = std::min(ret, dfn[j]-dfn[nxt[j]]+1);
      }
    }
  }

  std::cout << ret;

  return 0;
}
