#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];
int vals[maxN], cards[maxN];

long long dp[45][45][45][45];
int card[5];
int length;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  orep(i, 0, n) { scanf("%d", vals+i); }
  orep(i, 0, m) {
    scanf("%d", cards+i);
    card[cards[i]]++;
  }

  dp[0][0][0][0] = vals[0];

  orep(i, 0, card[1]+1) {
    orep(j, 0, card[2]+1) {
      orep(k, 0, card[3]+1) {
        orep(l, 0, card[4]+1) {
            dp[i][j][k][l] = std::max(
              { (i ? dp[i-1][j][k][l] : 0)
              , (j ? dp[i][j-1][k][l] : 0)
              , (k ? dp[i][j][k-1][l] : 0)
              , (l ? dp[i][j][k][l-1] : 0)
              }) + vals[i+j*2+k*3+l*4];
        }
      }
    }
  }
  printf("%lld", dp[card[1]][card[2]][card[3]][card[4]]);
  return 0;
}
