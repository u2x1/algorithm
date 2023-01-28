#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e3+5;
std::string arr[maxN];
int side[maxN][maxN];
struct pt { int x, y; };

int n, m;

bool check(int x, int y) {
  if (x < 0 || x == n || y == m || y < 0) { return 0; }
  return arr[x][y] == '.';
}

void count(int x, int y) {
  const int diff[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
  orep(i, 0, 4) {
    if (check(x+diff[i][0], y+diff[i][1])) {
      side[x][y]++;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> m;
  orep(i, 0, n) {
    std::cin >> arr[i];
  }
  std::queue<pt> firm;
  int zeros = 0;
  orep(i, 0, n) {
    orep(j, 0, m) {
      if (check(i, j)) {
        zeros++;
        count(i, j);
        if (side[i][j]==0) {
          std::cout << "Not unique"; return 0;
        } else if (side[i][j]==1) {
          firm.push({i,j});
        }
      }
    }
  }

  int cnt = 0;
  while(!firm.empty()) {
    const int diff[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    const int xx = firm.front().x, yy = firm.front().y;
    firm.pop();
    if (!check(xx,yy)) { continue; }
    int oxx, oyy;
    orep(i, 0, 4) {
      const int xxx = xx+diff[i][0], yyy = yy+diff[i][1];
      if (check(xxx,yyy)) { oxx = xxx; oyy = yyy; break; }
    }
    side[xx][yy] = side[oxx][oyy] = 0;
    if (xx == oxx) {
      arr[xx][std::min(oyy, yy)] = '<';
      arr[xx][std::max(oyy, yy)] = '>';
    } else {
      arr[std::min(oxx, xx)][yy] = '^';
      arr[std::max(oxx, xx)][yy] = 'v';
    }
    cnt += 2;
    orep(i, 0, 4) {
      const int xxx = oxx+diff[i][0], yyy = oyy+diff[i][1];
      if (check(xxx,yyy) && side[xxx][yyy]) { if(--side[xxx][yyy] == 1) { firm.push({xxx,yyy}); } }
    }
  }
  if (zeros != cnt) {
    std::cout << "Not unique"; return 0;
  } else {
    orep(i, 0, n) {
      std::cout << arr[i]; NL;
    }
  }

  return 0;
}
