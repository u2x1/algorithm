#include <cstdio>

#define cfor(i,a,b,step)  for(auto i=(a); i!=(b); i+=step)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  long long sum = 0;
  int tmp;
  cfor(i, 0, n, 1) {
    scanf("%d", &tmp);
    ++arr[tmp]; ++sum;
  }
  cfor(i, 0, q, 1) {
    scanf("%d", &tmp);
    printf("%lld", sum - arr[tmp]); NL;
  }
  return 0;
}