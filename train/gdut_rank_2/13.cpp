#include <iostream>
#include <queue>
#include <cstring>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e2+5;
unsigned long long val[maxN], cnt;
int l[maxN], r[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  memset(l, -1, sizeof(l));
  memset(r, -1, sizeof(r));
  int n; std::cin >> n;
  unsigned long long tmp; std::cin >> tmp; val[cnt++] = tmp;
  orep(i, 1, n) {
    std::cin >> tmp; val[cnt++] = tmp;
    int u = 0;
    while(1) {
      if (tmp > val[u]) {
        if (~l[u]) { u = l[u]; continue; }
        l[u] = cnt-1;
        break;
      } else if (tmp < val[u]) {
        if (~r[u]) { u = r[u]; continue; }
        r[u] = cnt-1;
        break;
      }
    }
  }
  std::queue<int> q; q.push(0);
  bool notfst = 0;
  bool perf = 1;
  while(!q.empty()) {
    if (notfst) { std::cout << " "; }
    const int u  = q.front(); q.pop();
    if((l[u]==-1) ^ (r[u]==-1)) { perf = 0; }
    if (~l[u]) { q.push(l[u]); }
    if (~r[u]) { q.push(r[u]); }
    std::cout << val[u]; 
    notfst = 1;
  }
  NL;
  std::cout << (perf ? "YES" : "NO");

  return 0;
}
