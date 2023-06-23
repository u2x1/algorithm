#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int fa[maxN], arr[maxN];

int find(int x) { return (x == fa[x] ? x : fa[x] = find(fa[x])); }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, maxN) { fa[i] = i; }
  orep(i, 0, n) { std::cin >> arr[i]; }
  int ret = 0;
  for(int i = 0, j = n-1; i < j; ++i, --j) {
    int fa1 = find(arr[i]), fa2 = find(arr[j]);
    if (fa1 != fa2) { ++ret; }
    fa[fa1] = fa2;
  }
  std::cout << ret;

  return 0;
}
