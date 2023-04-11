#include <iostream>
#include <cstring>
#include <string>

#define orep(i, a, b) for(int i = (a); i < (b); ++i)
#define NL std::cout << '\n'

const int maxN = 50+5;
int arr[maxN][maxN];
bool vis[maxN][maxN];
int color[maxN][maxN];
bool dead[6000];

void dfsZero(const int c, const int x, const int y) {
  if (vis[x][y] || arr[x][y] == 1) {
    return;
  }
  color[x][y] = c; vis[x][y] = 1;
  if (arr[x][y] == 2) {
    dead[c] = 1;
    return;
  }
  dfsZero(c, x+1, y); dfsZero(c, x-1, y);
  dfsZero(c, x, y+1); dfsZero(c, x, y-1);
  dfsZero(c, x+1, y+1); dfsZero(c, x-1, y-1);
  dfsZero(c, x-1, y+1); dfsZero(c, x+1, y-1);
}

bool dfs(const int x, const int y) {
  if (vis[x][y] || arr[x][y] != 1) {
    return false;
  }
  vis[x][y] = 1;
  dfs(x+1, y); dfs(x-1, y);
  dfs(x, y+1); dfs(x, y-1);
  return 1;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    memset(vis, 0, sizeof(vis));
    memset(dead, 0, sizeof(dead));
    int m, n; std::cin >> m >> n;
    std::string s;
    orep(i, 1, m+1) {
      std::cin >> s;
      orep(j, 1, n+1) {
        arr[i][j] = s[j-1]-'0';
      }
    }
    orep(i, 0, m+2) {
      orep(j, 0, n+2) {
        if (!i || !j || i == m+1 || j == n+1) {
          arr[i][j] = 2;
        }
      }
    }
    
    orep(i, 1, m+1) {
      orep(j, 1, n+1) {
        if (arr[i][j]) {
          continue;
        }
        dfsZero(i*100+j, i, j);
        vis[i][j] = 0;
        if (!dead[color[i][j]]) {
          arr[i][j] = 1;
          
        }
      }
    }
//    orep(i, 0, m+2) {
//      orep(j, 0, n+2) {
//        std::cout << arr[i][j];
//      } NL;
//    }
    int ret = 0;
    orep(i, 1, m+1) {
      orep(j, 1, n+1) {
        ret += dfs(i,j);
      }
    }
    std::cout << ret; NL;
  }
  
	return 0;
}
