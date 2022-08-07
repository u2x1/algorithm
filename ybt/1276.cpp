#include <cstdio>
#include <cstring>
#define LEN 99999
char a[LEN], b[LEN];

int main() {
  scanf("%s%s", a, b);

  int lena = strlen(a), lenb = strlen(b);
  int dp[lena+1][lenb+1];

  for(int i=1; i<=lena; ++i) { dp[i][0] = i; }
  for(int i=1; i<=lenb; ++i) { dp[0][i] = i; }

  for(int i = 1; i <= lena; ++i) {
    dp[i] = std::min(dp
  }
  printf("

  return 0;
}
