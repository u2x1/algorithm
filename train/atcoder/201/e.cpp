#include <iostream>
#include <cstring>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
const int mod = 1e9+7;
bool vis[maxN]; long long xdis[maxN];

std::vector<std::pair<int, unsigned long long>> son[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int N; std::cin >> N;
  orep(i, 0, N) {
    long long a, b, w; std::cin >> a >> b >> w;
    son[a].emplace_back(b, w);
    son[b].emplace_back(a, w);
  }
  vis[1] = 1;
  std::vector<int> q {1};
  orep(i, 0ul, q.size()) {
    auto u = q[i];
    for(auto [v, w] : son[u]) {
      if (!vis[v]) {
        q.emplace_back(v);
        vis[v] = 1;
        xdis[v] = xdis[u] ^ w;
      }
    }
  }
  long long ret = 0;
  orep(i, 0, 60) {
    std::vector<long long> cnt(2, 0);
    orep(j, 1, N+1) { cnt[(xdis[j]>>i)&1]++; }
    ret = (ret + (1ll<<i)%mod*cnt[0]%mod*cnt[1]%mod) % mod;
  }
  std::cout << ret;

  return 0;
}
