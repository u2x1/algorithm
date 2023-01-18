#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 300+5;
int dp[maxN][maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  std::string s, p; std::cin >> s >> p;
  dp[0][0] = 1;
  orep(i, 0ul, s.size()+1) {
    orep(j, 1ul, p.size()+1) {
      if (p[j-1] == '.' && i) {
        dp[i][j] = dp[i-1][j-1];
      } else if (p[j-1] == '*') {
        dp[i][j] = dp[i][j-2];
        char fst = p[j-1] == '.' ? s[i-1] : p[j-2];
        for(int k = i; k >= 1; --k) {
          if (s[k-1] != fst) { break; }
          if (dp[k-1][j-2]) { dp[i][j] = 1; break; }
        }
      } else if (i){
        dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
      }
    }
  }
  std::cout << (dp[s.size()][p.size()] ? "true" : "false");

  return 0;
}
