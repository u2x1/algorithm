#include <iostream>
#include <cstring>
#include <string>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 8e2+5;
std::string map[maxN];
int qcMap[maxN][maxN]; bool qcVis[maxN][maxN];
int n, m;

struct st { int x, y, s;};
std::queue<st> q;

void check(const int x, const int y, const int step) {
  if (x < 0 || x == n || y < 0 || y == m || map[x][y] == '#' || qcVis[x][y]) { return; }
  qcVis[x][y] = 1;
  qcMap[x][y] = step;
  q.push({x,y, step});
}

void bfs(const int xx, const int yy) {
  check(xx,yy, 0);
  while(!q.empty()) {
    const int x = q.front().x, y = q.front().y, step = q.front().s;
    q.pop();
    check(x+1, y, step+1); check(x-1, y, step+1);
    check(x, y+1, step+1); check(x, y-1, step+1);
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int sx, sy, q;
  std::cin >> n >> m >> sx >> sy >> q;
  orep(i, 0, n) {
    std::cin >> map[i];
  }
  memset(qcMap, -1, sizeof(qcMap));
  bfs(sx, sy);
  orep(i, 0, q) {
    int tx,ty; std::cin >> tx >> ty;
    int step = 0;
    while(1) {
      if (~qcMap[tx][ty] && qcMap[tx][ty] <= step) {
        std::cout << step; goto fend;
      }
      if (map[tx][ty] == 'L') {
        if (map[tx][ty-1] == '#') {
          if (~qcMap[tx][ty]) {
            std::cout << qcMap[tx][ty]; goto fend;
          } else {
            std::cout << -1; goto fend;
          }
        }
        ty--;
      } 
      else if (map[tx][ty] == 'R') {
        if (map[tx][ty+1] == '#') {
          if (~qcMap[tx][ty]) {
            std::cout << qcMap[tx][ty]; goto fend;
          } else {
            std::cout << -1; goto fend;
          }
        }
        ty++; 
      }
      else if (map[tx][ty] == 'U') {
        if (map[tx-1][ty] == '#') {
          if (~qcMap[tx][ty]) {
            std::cout << qcMap[tx][ty]; goto fend;
          } else {
            std::cout << -1; goto fend;
          }
        }
        tx--;
      }
      else if (map[tx][ty] == 'D') {
        if (map[tx+1][ty] == '#') {
          if (~qcMap[tx][ty]) {
            std::cout << qcMap[tx][ty]; goto fend;
          } else {
            std::cout << -1; goto fend;
          }
        }
        tx++;
      }
      else if (map[tx][ty] == '.') {
        if (~qcMap[tx][ty]) {
          std::cout << qcMap[tx][ty]; goto fend;
        }
        std::cout << -1; goto fend;
      }
      ++step;
    }
fend:;
     NL;
  }
  return 0;
}
