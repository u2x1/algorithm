#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int par[maxN], arr[maxN];

int find(const int x) { return x == par[x] ? x : (par[x] = find(par[x])); }
void merge(const int x, const int y) { const int u=find(x),v=find(y); if(u!=v) { par[u] = v; } }


int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, n) { std::cin >> arr[i]; par[i+1] = i+1; }
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    merge(arr[a-1], arr[b-1]);
  }
  int ret = 0;
  orep(i, 0, n) {
    if (arr[i] == i+1 || find(arr[i]) == find(i+1)) {
      ret++;
    }
  }
  std::cout << ret;

  return 0;
}
