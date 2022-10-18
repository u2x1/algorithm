#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int arr[105][105];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  crep(i, 1, n) {
    crep(j, 1, m) {
      scanf("%d", &arr[i][j]);
      arr[i][j] += arr[i][j-1] + arr[i-1][j]-arr[i-1][j-1];
    }
  }
  int max = 1;
  crep(i, 1, n) {
    crep(j, 1, m) {
      for(int k = max; ; ++k) {
        const int ii = i-k, jj = j-k;
        if (ii < 1 || jj < 1) {break;}
        if (arr[i][j] + arr[ii][jj]
          - arr[i][jj] - arr[ii][j] == k*k) {
          max = k; }
      }
    }
  }

  printf("%d", max);

  return 0;
}
