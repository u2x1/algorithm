#include <cstdio>
#include <algorithm>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 2e3;
int arr[maxN];

int main() {
  int n,m,t; scanf("%d%d%d", &n, &m, &t);
  int tmp;
  long long rst = 0;
  cfor(i, 0, n, 1) {
    scanf("%d", &tmp);
    rst += std::min(tmp-1, m-tmp);
  }
  printf("%lld", rst * t);
  return 0;
}
