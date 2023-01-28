#include <iostream>
#include <vector>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e4+5;
struct st { int v, price; };

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m;
  while(std::cin >> n >> m) {
    std::vector in(n+1, std::vector<int>());
    std::vector<int> out(n+1, 0);
    std::vector<bool> used(n+1, 0);
    orep(i, 0, m) {
      int a, b; std::cin >> a >> b;
      in[b].push_back(a);
      out[a]++;
    }
    std::queue<st> q;
    orep(i, 1, n+1) {
      if (!out[i]) { q.push({i, 0}); used[i] = 1; }
    }
    long long ret = 0; int cnt = 0;
    while(!q.empty()) {
      const int vv = q.front().v, pp = q.front().price;
      q.pop();
      cnt++;
      ret += pp+888;
      orep(it, in[vv].cbegin(), in[vv].cend()) {
        --out[*it];
        if (out[*it] == 0 && !used[*it]) { q.push({*it, pp+1}); }
      }
    }
    std::cout << (cnt == n ? ret : -1); NL;
  }
  return 0;
}
