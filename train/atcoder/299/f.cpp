#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
const int mod = 998244353;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  std::vector<int> pos(26);
  std::vector<std::vector<int>> nxt(s.size()+1);
  for(int i = s.size()-1; ~i; --i) {
    nxt[i] = pos;
    pos[s[i]-'a'] = i;
  }
//  std::cout << s.size(); NL;
 const int n = s.size();
  long long ret = 0;
  orep(k, 0, n-1) {
    // std::cout << "-------" << k << "-------"; NL;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    // if (pos[s[k]-'a'] == k) { continue; }
    // dp[pos[s[k]-'a']][k] = 1;
    orep(c, 0, 26) {
      if(pos[c] == -1 || nxt[k][c] == -1) { continue; }
      dp[pos[c]][nxt[k][c]] = 1;
    }
    orep(i, 0, k+1) {
      orep(j, k+1, n) {
        orep(c, 'a', 'z'+1) {
          if (s[i] != s[j]) { continue; }
          // if (!dp[i][j]) { dp[i][j] = 1; }
          int nl = nxt[i][c-'a'], nr = nxt[j][c-'a'];
          if (!~nl || !~nr || nl > k) { continue; }
          // std::cout << "nxt " << i << " " << c << " IS " << nl; NL;
          // std::cout << "nxt " << j << " " << c << " IS " << nr; NL;
          dp[nl][nr] += dp[i][j];
          dp[nl][nr] %= mod;
          // std::cout << "on " << k; NL;
          // std::cout << nl << "," << nr << " " << dp[nl][nr] << " from " << i << " " << j << " " << dp[i][j]; NL;
        }
      }
    }
    orep(i, k+1, n) {
      if (s[k] != s[i]) { continue; }
      ret += dp[k][i];
      ret %= mod;
    }
    // orep(c, 0, 26) {
    //   if (!~nxt[k][c]) { continue; }
    //   ret += dp[k][nxt[k][c]];
    // }
    // orep(i, 0, k+1) {
    //   orep(j, k+1, n) {
    //     if (s[i] != s[j]) { continue; }
    //     if (nxt[i][s[k]-'a'] != k) { continue; }
    //     ret += dp[i][j];
    //     ret %= mod;
    //   }
    // }
  }
  std::cout << ret;

  return 0;
}
