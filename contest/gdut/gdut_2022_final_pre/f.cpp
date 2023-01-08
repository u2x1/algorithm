#include <cstdio>
#include <cmath>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
const long double PI = acos(-1);

int main() {
  double a, x; scanf("%lf%lf", &a, &x);
  const long double d = x*cos(PI * a / 180.0);
  const long double r = d*tan(PI * (a/2) / 180.0);
  const long double c = 2*PI*r;
  printf("%.8Lf", c);
  return 0;
}
