#include <cstdio>
#include <cstring>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

long long prefix[1004], secPrefix[1004], actual[1004], sum[1004];

int main() {
  int n, m; scanf("%d%d", &n, &m);
  crep(i, 1, n) {
    scanf("%lld", actual+i);
    sum[i] = actual[i] + sum[i-1];
  }
  orep(i, 0, m) {
    int op, x, y; scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      prefix[x] += actual[y]-actual[x];
      prefix[y] += actual[x]-actual[y];
      std::swap(actual[x], actual[y]);
    } else {
      memset(secPrefix, 0, sizeof(secPrefix));
      crep(j, 1, n) { secPrefix[j] = prefix[j] + secPrefix[j-1]; }
      if (x > y) { std::swap(x, y); }
      printf("%lld", sum[y] + secPrefix[y] - (sum[x-1] + secPrefix[x-1])); NL;
    }
  }
  return 0;
}
