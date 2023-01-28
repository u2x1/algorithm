#include <iostream>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';
const int maxN = 2e5+5;

int par[maxN];

int find(const int x) { return x==par[x] ? x : (par[x] = find(par[x])); }

void merge(const int u, const int v) {
  const int x = find(u), y = find(v);
  if (x != y) { par[x] = y; }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  orep(i, 1, n+m+2) { par[i] = i; }
  int langs = 0;
  orep(i, 0, n) {
    int num; std::cin >> num;
    orep(j, 0, num) {
      int lang; std::cin >> lang; langs += lang;
      merge(lang+n, i+1);
    }
  }
  int ret = 0;
  orep(i, 1, n+1) {
    ret += (find(i) == i);
  }
  std::cout << ret-1+(langs==0);
  return 0;
}
