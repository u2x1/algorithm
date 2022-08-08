#include <cstdio>
#include <cstring>

#define orep(i, a, b) for (int i = (a); i <  b; ++i)
#define crep(i, a, b) for (int i = (a); i <= b; ++i)
#define _CMP(a, b, op) ((a) op (b) ? a : b)
#define min(a, b) _CMP(a, b, <)
#define max(a, b) _CMP(a, b, >)
#define min3(a, b, c) min(min(a,b),c)
#define max3(a, b, c) max(max(a,b),c)
#define printArr(type,arr,len,split) orep(i,0,len) { printf("%" type, arr[i]); putchar(split); }

char a[1001], b[1001];
int dp[1001][1001];

int main() {
  int n;
  scanf("%d", &n);

  while(n--) {
    scanf("%s%s", a+1, b+1);
    const int la = strlen(a+1), lb = strlen(b+1);
    printArr("c", a, la+1, 0);

    crep(i, 0, la) { dp[i][0] = i; }
    crep(i, 0, lb) { dp[0][i] = i; }

    crep(i, 1, la) {
      crep(j, 1, lb) {
        if (a[i] == b[j]) { dp[i][j] = dp[i-1][j-1]; }
        else {
          dp[i][j] = min3(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1);
        }
      }
    }

    printf("%d\n", dp[la][lb]);
  }

  return 0;
}
