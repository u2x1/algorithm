#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 25;
long long arr[maxN];

unsigned long long lcm(long long a, long long b) {return a/std::__gcd(a,b)*b;}

int main() {
  long long l, r, k; scanf("%lld%lld%lld", &l, &r, &k);
  orep(i, 0, k) { scanf("%lld", arr+i); }
  long long ret = 0ll;
  const long long bound = 1ll << k;
  for(long long i = 1ll; i < (bound); ++i) {
    long long div = 1ll, cnt = 0;
    for(int j = 0; j < k; ++j) {
      if (i & (1ll<<j)) {
        div = lcm(div, arr[j]);
        if (div > r) { break; }
        ++cnt;
      }
    }
    if (div > r) { continue; }
    long long mod = (r/div) - ((l-1)/div);
    ret += (cnt&1) ? mod : -mod;
  }
  printf("%lld", (r-l+1ll)-ret);
  return 0;
}
