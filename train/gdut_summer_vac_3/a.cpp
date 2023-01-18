#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';
#define M 998244353
const int maxN = 4e6+5;
int p[maxN];

int find(int x) {
  if (p[x] == x) { return x; }
  return p[x] = find(p[x]);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  orep(i, 0, n+1) { p[i] = i; }
  long long ret = 0ll;
  orep(i, 0, m) {
    int op, a, b; std::cin >> op >> a >> b;
    if (!op) {
      p[find(b)] = find(a);
    } else {
      ret = (ret << 1) % M;
      ret += find(b) == find(a);
    }
  }
  std::cout << ret % M;

  return 0;
}
