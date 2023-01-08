#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 7;
long long arr[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    long long n; scanf("%lld", &n);
    memset(arr, 0, sizeof(arr));
    orep(i, 0, n) {
      int tmp; scanf("%d", &tmp);
      ++arr[tmp%6];
    }
    long long cnt = arr[0] ? (arr[0] * (arr[0]-1)) : 0;
    orep(i, 1, 3) {
      cnt += arr[i] * arr[6-i] * 2;
    }
    cnt += arr[3] ? (arr[3] * (arr[3]-1)) : 0;
    printf("%.6f", (1.0*cnt/(n*(n-1)))); NL;
  }
  return 0;
}
