#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

int main() {
  long long k, d, t; scanf("%lld%lld%lld", &k, &d, &t);
  if (k >= t || d == k) { printf("%lld.000000000", t); return 0; }
  t*=2;
  long long time = d > k ? d : (k+(d-k%d)), eff = d > k ? (2*k+(d-k)) : 2*k+(d-k%d);
  long long prevEff = t/eff;
  t -= prevEff*eff;
  double ret = (t < 2*k ? t/2.0 : k+(t-2.0*k)) + prevEff*time;
  printf("%.10f", ret);
  return 0;
}
