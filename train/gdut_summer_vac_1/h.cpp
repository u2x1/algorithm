#include <cstdio>
#include <vector>

#define NL putchar(10);

const int maxN = 2e5;
const double eps = 1e-15;

int n; double a[maxN], b[maxN], c[maxN];

double check(double x) {
  double max; bool fst = 1;
  for(int i = 0; i < n; ++i) {
    const double cur = (a[i]*x*x+b[i]*x+c[i]);
    max = fst ? (fst=0,cur) : max > cur ? max : cur;
  }
  return max;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) { scanf("%lf%lf%lf", a+i, b+i, c+i); }
    double l = 0.0, r = 1000.0;
    while(l < r-eps) {
      const double m1 = l+(r-l)/3.0, m2 = l+2*(r-l)/3.0;
      const double y1 = check(m1), y2 = check(m2);
      if (y1 > y2) { l = m1; }
      else { r = m2; }
    }
    printf("%.4f", check(r)); NL;
  }
  return 0;
}
