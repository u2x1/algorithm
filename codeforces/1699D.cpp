#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 5e3+5;
int arr[maxN];
bool del[maxN][maxN];
int freq[maxN], add[maxN], cnt;
int dp[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    orep(i, 0, n) { std::cin >> arr[i]; }
    orep(i, 0, n) {
      // del[i][i] = 1;
      while(cnt) { freq[add[--cnt]] = 0; }
      int mx = arr[i]; freq[add[cnt++] = arr[i]] = 1;
      orep(j, i+1, n) {
        ++freq[arr[j]];
        if (freq[arr[j]] == 1) { add[cnt++] = arr[j]; }
        if (freq[arr[j]] > freq[mx]) { mx = arr[j]; }
        if ((j-i)&1 && freq[mx]*2 <= j-i+1) { del[i][j] = 1; }
        else { del[i][j] = 0; }
        // std::cout << "del " << i << ", " << j << " : " << del[i][j]; NL;
      }
    }
    orep(i, 0, n) {
      dp[i] = !i || del[0][i-1];
      orep(j, 0, i) {
        if (arr[j] == arr[i] && dp[j]) {
          if (j == i-1 || del[j+1][i-1]) {
            dp[i] = std::max(dp[i], dp[j] + 1);
            // std::cout << "dp " << i << " transfer from " << j << " to :: " << dp[i]; NL;
          }
        }
      }
    }
    int ret = 0;
    orep(i, 0, n) {
      // std::cout << del[i+1][n-1] << " ";
      if (dp[i] && (i == n-1 || del[i+1][n-1])) {
        // std::cout << "dp " << i << " " << dp[i]; NL;
        ret = std::max(ret, dp[i]);
      }
    }
    std::cout << ret; NL;
  }

  return 0;
}
