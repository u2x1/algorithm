#include <iostream>
#include <queue>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'
#define int long long

const int maxN = 2e5+5;
const int mod = 1000000007;
int arr[maxN];
int a[maxN], b[maxN];
struct st { int to, c; };
std::vector<st> son[maxN];
int ind[maxN];
int f[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k; std::cin >> n >> m >> k;
  orep(i, 0, k) { std::cin >> a[i] >> b[i]; }
  orep(i, 0, m) {
    int x, y, c; std::cin >> x >> y >> c;
    ind[y]++; son[x].push_back({y, c});
  }
  std::queue<int> q;
  orep(i, 1, n+1) { if (!ind[i]) { q.push(i); } }
  while(q.size()) {
    const int u = q.front(); q.pop();
    f[u]++; f[u] %= mod;
    for(const auto [v, c] : son[u]) {
      --ind[v];
      f[v] += c*f[u]%mod;
      f[v] %= mod;
      if (!ind[v]) { q.push(v); }
    }
  }
  int ret = 0;
  orep(i, 0, k) {
    ret += f[a[i]] * b[i] % mod;
    ret %= mod;
  }
  std::cout << ret; NL;

  return 0;
}
