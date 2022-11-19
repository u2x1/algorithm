#include <cstdio>
#include <algorithm>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 1e5;

int main() {
  int n, tmp;
  int rst = -1, final;
  scanf("%d", &n);
  cfor(i, 0, n, 1) {
    scanf("%d", &tmp);
    if (rst < (int)(tmp/10)+tmp%10) {
      rst = (int)(tmp/10)+tmp%10;
      final = tmp;
    }
  }
  printf("%d", final);
  return 0;
}
