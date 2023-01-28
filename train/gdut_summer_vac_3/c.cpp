#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN], par[maxN], cnt;
bool used[maxN];

int find(const int x) { return x == par[x] ? x : (par[x] = find(par[x])); }

void merge(const int x, const int y) {
  const int u = find(x), v = find(y);
  if (u != v) { par[u] = v; }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  while(1) {
    int n, m; std::cin >> n >> m;
    if (!n && !m) { return 0; }
    orep(i, 0, n+m+2) { par[i] = i; }
    cnt = 0;
    orep(i, 1, m+1) {
      int len; std::cin >> len;
      orep(j, 0, len) {
        int pers; std::cin >> pers;
        if (pers && !used[pers]) { arr[cnt++] = pers; used[pers] = 1; }
        merge(pers, n+i);
      }
    }
    int zeroPar = find(0);
    int ret = 1;
    orep(i, 0, cnt) {
      if (find(arr[i]) == zeroPar) {
        ret++;
      }
      used[arr[i]] = 0;
    }
    std::cout << ret << NL;
  }

  return 0;
}
