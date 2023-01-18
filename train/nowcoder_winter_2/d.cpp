#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int d[maxN], p[maxN];

int fa(int x) {
  if (x == p[x]) { return x; }
  int curPar = p[x];
  p[x] = fa(p[x]);
  d[x] += d[curPar];
  return p[x];
}

void conn(int a, int b) {
  p[a] = fa(b);
  d[a] = d[b] + 1;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  orep(i, 1, n+1) { p[i] = i; }
  orep(i, 2, n+1) {
    int par; std::cin >> par;
    conn(i, par);
  }
  orep(i, 2, n+1) { fa(i); }
  std::vector<int> e(n);
  long long ret = 0;
  orep(i, 0, n) { std::cin >> e[i]; ret += e[i]; }
  std::sort(e.begin(), e.end());
  std::sort(d+2, d+n+1);
  orep(i, 2, n+1) {
    ret += 1ll * e[i-1] * d[i];
  }
  std::cout << ret;

  return 0;
}
