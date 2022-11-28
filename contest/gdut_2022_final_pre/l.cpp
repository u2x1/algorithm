#include <cstdio>
#include <algorithm>
#include <cmath>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 2e5+5;
long long arr[maxN];

int main() {
  int n, q; scanf("%d%d", &n, &q);
  orep(i, 0, n) { scanf("%d", arr+i); }
  orep(i, 1, n) { arr[i] += arr[i-1]; }
  long long longest = -1;
  orep(i, 0, n) { 
    longest = std::max((long long)ceil(arr[i]/(i+1)), longest);
  }

  orep(i, 0, q) {
    int query; scanf("%d", &query);
    if (query < longest) {
      printf("-1");
    } else {
      printf("%lld", -1ll+(long long)ceil(1.0*arr[n-1]/query));
    }
    NL;
  }
  return 0;
}
