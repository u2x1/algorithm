#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int cnt[3];
int rcnt[10];
int dp[3][1<<10];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    memset(dp, 0, sizeof dp);
    memset(cnt, 0, sizeof cnt);
    orep(i, 0, 3) {
      std::string s; std::cin >> s;
      orep(j, 0, 10) {
        if (s[j] == '1') { cnt[i]++; }
      }
    }
    orep(a, 0, (1<<10)) {
      if (__builtin_popcount(a) != cnt[0]) { continue; }
      dp[0][a] = 1;
    }
    int ret = 0;
    orep(i, 1, 3) {
      orep(a, 0, (1<<10)) {
        if (!dp[i-1][a]) { continue; }
        orep(b, 0, (1<<10)) {
          if (__builtin_popcount(b) != cnt[i]) { continue; }
          dp[i][a^b] = 1;
          if (i == 2) { ret = std::max(ret, a^b); }
        }
      }
    }
    for(int i = 9; i > -1; --i) {
      std::cout << ((ret >> i) & 1);
    } NL;
  }

  return 0;
}
