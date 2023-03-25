#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e2+5;
bool white[maxN][maxN];
bool arr[2][maxN][maxN];
bool vis[2][maxN][maxN];

// bool kill(int t, int x, int y) {
//   bool ret = 0;
//   orep(i, 0, 16) {
//     if (arr[t][x][i]) { ret = 1; arr[t][x][i] = 0; }
//     if (arr[t][i][y]) { ret = 1; arr[t][x][i] = 0; }
//   }
//   for(int i = x, j = y; i > -1 && j > -1; --i, --j) {
//     if (arr[t][i][j]) { ret = 1; arr[t][i][j] = 0; }
//   }
//   for(int i = x, j = y; i < 16 && j < 16; ++i, ++j) {
//     if (arr[t][i][j]) { ret = 1; arr[t][i][j] = 0; }
//   }
//   for(int i = x, j = y; i > -1 && j < 16; --i, ++j) {
//     if (arr[t][i][j]) { ret = 1; arr[t][i][j] = 0; }
//   }
//   for(int i = x, j = y; i < 16 && j > -1; ++i, --j) {
//     if (arr[t][i][j]) { ret = 1; arr[t][i][j] = 0; }
//   }
//   return ret;
// }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::string s;
  int whitecnt = 0; int blackcnt = 0;
  std::cin >> n; orep(i, 0, n) {
    std::cin >> s;
    if (!arr[0][s[0]-'A'][s[1]-'1']) { arr[0][s[0]-'A'][s[1]-'1'] = 1; whitecnt++; }
  }
  std::cin >> n; orep(i, 0, n) {
    std::cin >> s;
    if (!arr[1][s[0]-'A'][s[1]-'1']) { arr[1][s[0]-'A'][s[1]-'1'] = 1; blackcnt++; }
  }
  // std::cout << whitecnt << " " << blackcnt; NL;
  std::cout << (whitecnt > blackcnt ? "Cuber QQ" : "Quber CC"); 
  return 0;
}
