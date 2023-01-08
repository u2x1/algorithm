#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <numeric>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5+10;
long long arr[maxN], tmp[maxN];

int main() {
  int n,t;
  scanf("%d%d", &n, &t);
  orep(i, 0, n) { scanf("%lld", arr+i); }
  while(t--) {
    int l, r; scanf("%d%d", &l, &r);
    --l; --r;
    const int len = r-l+1;
    memcpy(tmp, arr+l, len*sizeof(long long));
    const long long mx = *std::max_element(tmp, tmp+len);
    const long long sum = std::accumulate(tmp, tmp+len, 0ll);
    if (mx >= sum-mx) { printf("%lld", mx); }
    else { printf("%lld", (sum+1)/2); }
    NL;
  }
  return 0;
}
