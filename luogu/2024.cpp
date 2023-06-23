#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 5e4+5;
int fa[maxN*3];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  orep(i, 1, 3*n+1) { fa[i] = i; }
  int ret = 0;
  int e, a, b;
  orep(i, 0, k) {
    std::cin >> e >> a >> b;
    if (a > n || b > n) { ret++; }
    else if (e == 1) {
      if (find(a+n) == find(b) || find(b+n) == find(a)) { ret++; }
      else {
        fa[find(a)] = find(b);
        fa[find(a+n)] = find(b+n);
        fa[find(a+2*n)] = find(b+2*n);
      }
    } else {
      if (a == b) { ret++; }
      else if (find(a) == find(b) || find(b+n) == find(a)) { ret++; }
      else {
        fa[find(a)] = find(b+2*n);
        fa[find(a+n)] = find(b);
        fa[find(a+2*n)] = find(b+n);
      }
    }
  }
  std::cout << ret;


  return 0;
}
