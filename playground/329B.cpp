#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  n += 2; m += 2;
  std::vector<std::vector<char>> mp(n, std::vector<char>(m));
  orep(i, 0, n) { mp[i][0] = mp[i][m-1] = 'T'; }
  orep(i, 0, m) { mp[0][i] = mp[n-1][i] = 'T'; }
  int sx = -1, sy = -1;
  int ex = -1, ey = -1;
  orep(i, 1, n-1) {
    orep(j, 1, m-1) {
      std::cin >> mp[i][j];
      if (mp[i][j] == 'E') { sx = i; sy = j; }
      if (mp[i][j] == 'S') { ex = i; ey = j; }
    }
  }

  // for(auto x : mp) {
  //   for(auto y : x) { std::cout << y; } NL;
  // } NL;
  // std::vector<int> enm(1e6+5);

  const int inf = 0x3f3f3f3f;
  std::vector<std::vector<int>> tm(n, std::vector<int>(m, inf));
  tm[sx][sy] = 1;

  std::queue<std::pair<std::pair<int, int>, int>> q;
  q.push({{sx, sy}, 1});
  auto push = [&](int x, int y, int t) {
    if (tm[x][y] <= t || mp[x][y] == 'T') { return; }
    q.push({{x, y}, t}); tm[x][y] = t;
  };
  while(not q.empty()) {
    auto [pt, t] = q.front(); q.pop();
    auto [x, y] = pt;
    push(x+1, y, t+1); push(x-1, y, t+1); 
    push(x, y+1, t+1); push(x, y-1, t+1); 
  }
  int ret = 0;
  orep(i, 1, n-1) {
    orep(j, 1, m-1) {
      if (isdigit(mp[i][j]) && tm[i][j] <= tm[ex][ey]) { ret += mp[i][j]-'0'; }
    }
  }
  std::cout << ret;


  // std::vector<std::vector<int>> cost(n, std::vector<int>(m, inf));
  // q.push({{sx, sy}, 0});
  // auto ps = [&](int x, int y, int c) {
  //   if (cost[x][y] <= c || tm[x][y] == inf) { return; }
  //   q.push({{x, y}, c});
  // };
  // while(not q.empty()) {
  //   auto [pt, c] = q.front(); q.pop();
  //   auto [x, y] = pt;
  //   if (cost[x][y] <= c) { continue; }
  //   int t = tm[x][y];
  //   if (t*2-1 < n*m) { c += enm[t*2-1]; }
  //   if (t*2 < n*m) { c += enm[t*2]; }
  //   cost[x][y] = c;
  //   ps(x+1, y, c); ps(x-1, y, c); 
  //   ps(x, y+1, c); ps(x, y-1, c); 
  // }
  // for(auto x : cost) {
  //   for(auto y : x) { std::cout << (y == inf ? 0 : y); } NL;
  // }

  return 0;
}
