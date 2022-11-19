#include <cstdio>
#include <algorithm>
#include <set>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 1e5;

int main() {
  int t; scanf("%d", &t);
  while(t--){
    std::set<int> rst;
    int b; scanf("%d", &b);
    cfor(i, 1, 1001, 1) {
      rst.insert(i*b/std::__gcd(b, i)/i);
    }
    printf("%d", rst.size()); NL;
  }
  return 0;
}
