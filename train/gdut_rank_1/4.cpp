#include <iostream>
#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e6+5;
bool vis[maxN];
bool friended[maxN];
// int fa[maxN];
int ret[maxN], retCnt;

// int find(int u) {
//   if (u == fa[u]) { return u; }
//   return (fa[u] = find(fa[u]));
// }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  // orep(i, 0, 100000) {
  //   fa[i] = i;
  // }

  orep(i, 0, n) {
    int k; std::cin >> k;
    orep(j, 0, k) {
      int id; std::cin >> id;
      if (k > 1) {
        friended[id] = 1;
      }
      // if (id != fst) { friended[id] = 1; }
      // fa[id] = fa[fst];
    }
  }

  int m; std::cin >> m;
  orep(i, 0, m) {
    int id; std::cin >> id;
    if (vis[id]) { continue; }
    vis[id] = 1;
    if (!friended[id]) {
      ret[retCnt++] = id;
    }
  }

  if (!retCnt) {
    std::cout << "No one is handsome";
    return 0;
  }

  orep(i, 0, retCnt) {
    printf("%05d", ret[i]);
    if (i != retCnt - 1) {
      printf(" ");
    }
  }

  return 0;
}
