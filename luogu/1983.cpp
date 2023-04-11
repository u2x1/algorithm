#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
int arr[maxN], in[maxN];
bool used[maxN];
std::vector<int> son[maxN];
bool conn[maxN][maxN];

struct st { int u, dep; };

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, m) {
    int x; std::cin >> x;
    orep(j, 0, x) { std::cin >> arr[j]; used[arr[j]] = 1; }
    const int a = arr[0], b = arr[x-1];
    orep(j, a, b+1) {
      if (used[j]) { continue; }
      orep(k, 0, x) {
        if (conn[j][arr[k]]) { continue; } conn[j][arr[k]] = 1;
        ++in[arr[k]];
        son[j].emplace_back(arr[k]);
      }
    }
    orep(j, 0, x) { used[arr[j]] = 0; }
  }
  int ret = 0;
  std::queue<st> q;
  orep(i, 1, n+1) { if (!in[i]) { q.push({i, 1}); } }
  while(q.size()) {
    const int u = q.front().u, d = q.front().dep; q.pop();
    ret = std::max(d, ret);
    for(const int v : son[u]) {
      in[v]--;
      if (!in[v]) { q.push({v, d+1}); }
    }
  }
  std::cout << ret;
  return 0;
}
