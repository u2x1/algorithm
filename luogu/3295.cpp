#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int fa[maxN][20];
int find(int x, int k) { return fa[x][k] == x ? x : fa[x][k] = find(fa[x][k], k); }
void setfa(int x, int _fa, int k) { fa[find(x, k)][k] = find(_fa, k); }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(k, 0, 20) {
    orep(i, 1, n+1) {
      fa[i][k] = i;
    }
  }
  while(m--) {
    int l1, r1, l2, r2; std::cin >> l1 >> r1 >> l2 >> r2;
    int k = std::__lg(r1-l1+1);
    setfa(l1, l2, k);
    setfa(r1-(1<<k)+1, r2-(1<<k)+1, k);
  }
  for(int k = 20; k; --k) {
    for(int i = 1; i+(1<<k)-1 <= n; ++i) {
      int _fa = find(i, k);
      if (_fa == i) { continue; }
      setfa(i, _fa, k-1);
      setfa(i+(1<<(k-1)), _fa+(1<<(k-1)), k-1);
    }
  }
  long long ret = 0;
  const int mod = 1e9+7;
  orep(i, 1, n+1) {
    if (fa[i][0] != i) { continue; }
    ret = ret ? ret*10%mod : 9;
  }
  std::cout << ret;

  return 0;
}
