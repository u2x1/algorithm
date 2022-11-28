#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

long long memo[20][20];

long long cal(int in, int out) {
  if (in == 0) { return 1; }
  if (memo[in][out]) { return memo[in][out]; }
  return (memo[in][out] =
    cal(in-1,out) + (in==out?0:cal(in, out-1)));
}

int main() {
  int n; scanf("%d", &n);
  printf("%lld", cal(n, n));
  return 0;
}
