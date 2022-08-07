#include <cstdio>
#include <algorithm>

int atoi(char *arr, int l, int r) {
  int ret = 0;
  while(l<=r) {
    ret = ret*10 + (arr[l] - '0');
    ++l;
  }
  return ret;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  char arr[n+1];
  scanf("%s", arr);

  int num[n+1][n+1], dp[n+1][k+1]={};
  for(int i=0; i<n; ++i) {
    num[i][i] = 0;
    for(int j=i; j<n; ++j) {
      num[i][j] = atoi(arr, i, j);
    }
  }

  for(int i=0; i<n; ++i) { dp[i][0] = num[0][i]; }

  for(int star=1; star<=k; ++star) {
    for(int i=star; i<n; ++i) {
      for(int j=star-1; j<i; ++j) {
        dp[i][star] = std::max(dp[i][star], dp[j][star-1] * num[j+1][i]);
      }
    }
  }

  printf("%d", dp[n-1][k]);

  return 0;
}
