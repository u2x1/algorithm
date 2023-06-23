#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e3+5;
bool arr[maxN][maxN];
int dp[maxN][maxN];

int up[maxN], dn[maxN];
struct st { int val, idx; };

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 1, n+1) {
    orep(j, 1, m+1) {
      std::string s; std::cin >> s;
      arr[i][j] = s == "F";
      if (arr[i][j]) { dp[i][j] = 1+dp[i][j-1]; }
    }
  }
  // orep(i, 1, n+1) { orep(j, 1, m+1) { std::cout << dp[i][j] << " "; } NL; }
  int ret = 0;
  orep(j, 1, m+1) {
    std::vector<st> stk;
    orep(i, 1, n+1) { up[i] = 0; dn[i] = n+1; }
    orep(i, 1, n+1) {
      while(stk.size() && stk.back().val > dp[i][j]) { dn[stk.back().idx] = i; stk.pop_back(); }
      if(stk.size()) { up[i] = stk.back().idx; }
      stk.push_back({dp[i][j], i});
    }
    // while(stk.size() > 1) { up[stk.back()] = stk[stk.size()-2]; stk.pop_back(); }
    orep(i, 1, n+1) {
      ret = std::max(dp[i][j]*(dn[i]-1-(up[i]+1)+1), ret);
    }
  }
  std::cout << ret * 3;

  return 0;
}
