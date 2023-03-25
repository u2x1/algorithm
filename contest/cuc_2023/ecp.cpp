#include <iostream>
#include <queue>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int a[3][3];
int dp[2000];
bool vis[2000];

const std::vector<int> get(const int x) {
  std::vector<int> ret;
  // drep(i, 8, -1) { std::cout << ((x>>i)&1) << "\n\0"[i%3]; } NL;
  orep(i, 0, 9) {
    int y = 0;
    if (i-3 > -1) { y |= (1 << (i-3)); }
    if (i-1 > -1 && i%3) { y |= (1 << (i-1)); }
    if (i+3 < 9) { y |= (1 << (i+3)); }
    if (i+1 < 9 && (i+1)%3) { y |= (1 << (i+1)); }
    y |= (1 << i);
    y ^= x;
    ret.emplace_back(y);
    // drep(i, 8, -1) { std::cout << ((y>>i)&1) << "\n\0"[i % 3]; } NL;
  }
  return ret;
}

struct st{int a,b;};
int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::queue<st> q; q.push({0, -1});
  while(q.size()) {
    const int x = q.front().a, fa = q.front().b;  q.pop();
    if(dp[x]) { continue; }
    dp[x] = fa+1;
    const auto ys = get(x);
    for(const auto y : ys) {
      if (!vis[y] && y) { q.push({y, fa+1}); }
    }
  }
  int x, y = 0;
  orep(i, 0, 9) { std::cin >> x; y = (y<<1) | x; }
  std::cout << dp[y];

  return 0;
}
