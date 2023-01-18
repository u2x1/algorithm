#include <iostream>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 5e5+5;
int fromTop[maxN][4], fromBot[maxN][5];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  while(t--) {
    int n, k; std::cin >> n >> k;
    orep(i, 0, k) {
      int x, y; std::cin >> x >> y;
      fromTop[x][y] = ~fromTop[x][y];
      fromBot[x][y] = ~fromBot[x][y];
    }
    fromTop[1][1] = 1;
    orep(i, 1, n+1) {
      orep(j, 1, 4) {
        if (fromTop[i][j]) { continue; }
        fromTop[i][j] = (fromTop[i-1][j] == 1 || fromTop[i][j-1] == 1);
      }
    }
    int ret = -1;
    if (!fromTop[n][3]) { std::cout << 0 << NL; goto reset; }
    fromBot[n][3] = 1;
    for(int i = n; i > 0; --i) {
      for(int j = 3; j > 0; --j) {
        if (fromBot[i][j]) { continue; }
        fromBot[i][j] = (fromBot[i+1][j] == 1) || (fromBot[i][j+1] == 1);
      }
    }
    orep(i, 1, n+1) {
      orep(j, 1, 4) {
        ret += fromBot[i][j]==1 && fromTop[i][j]==1;
      }
    }
    std::cout << ret << NL;
    // memset(fromBot, 0, (n+2)*5*sizeof(int));
    // memset(fromTop, 0, (n+2)*4*sizeof(int));
reset:
    orep(i, 1, n+1) {
      orep(j, 1, 4) {
        fromTop[i][j] = fromBot[i][j] = 0;
      }
    }
  }

  return 0;
}
