#include <iostream>
#include <queue>
#include <string>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 5e3+5;
bool arr[maxN][maxN];
int dis[maxN][maxN];
struct st { int x, y, c; };
bool vis[maxN][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  int r, c; std::cin >> r >> c; --r; --c;
  int x, y; std::cin >> x >> y;
  orep(i, 0, n) {
    std::string s; std::cin >> s;
    orep(j, 0, m) {
      arr[i][j] = s[j] == '.';
    }
  }
  std::queue<st> q;
  const auto isvalid = [&](const int i, const int j) { return i >= 0 && j >= 0 && i < n && j < m && arr[i][j]; };
  const auto push = [&](const int i, const int j, const int cc) { if (isvalid(i, j) && dis[i][j] > cc) { q.push({i, j, cc}); } };

  int ret = 0;
  memset(dis, 0x3f, sizeof(dis));

  push(r, c, 0);
  while(q.size()) {
    const auto xx = q.front().x, yy = q.front().y, cc = q.front().c; q.pop();
    if (dis[xx][yy] <= cc) { continue; }
    if (cc > x || cc+yy-c > y) { continue; }
    push(xx+1, yy, cc);
    push(xx-1, yy, cc);
    push(xx, yy-1, cc+1);
    push(xx, yy+1, cc);
    dis[xx][yy] = cc;
    if(!vis[xx][yy]) { vis[xx][yy] = 1; ++ret; }
  }
  std::cout << ret;

  return 0;
}
