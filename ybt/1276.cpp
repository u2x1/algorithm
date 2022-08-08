#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEN 3999
char a[LEN], b[LEN];
int dp[LEN][LEN]={};


int main() {
  scanf("%s%s", a+1, b+1);

  int lena = strlen(a+1), lenb = strlen(b+1);

  for(int i=1; i<=lena; ++i) { dp[i][0] = i; }
  for(int i=1; i<=lenb; ++i) { dp[0][i] = i; }

  for(int i = 1; i <= lena; ++i) {
    for(int j = 1; j <= lenb; ++j) {
      if (a[i] == b[j]) { dp[i][j] = dp[i-1][j-1]; }
      else {
        dp[i][j] = std::min(std::min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1);
      }
    }
  }
  printf("%d", dp[lena][lenb]);

  return 0;
}
