#include <cstdio>
#include <set>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

int main() {
  int n;
  while(scanf("%d", &n) == 1) {
    std::set<long long> reach = {0};
    long long tmp, sum=0, half;
    cfor(i, 0, n, 1) {
      scanf("%lld", &tmp);
      sum += tmp;
      reach.insert(sum);
    }
    if (sum&1ll) { printf("0"); NL; continue; }
    half = sum/2;
    long long rst = 0;
    for(auto it = reach.cbegin(); it != reach.cend() && *it < half; ++it) {
      if (reach.find((*it)+half) != reach.cend()) {
        ++rst;
      }
    }
    printf("%lld", (rst*(rst-1))/2); NL;
  }
  return 0;
}
