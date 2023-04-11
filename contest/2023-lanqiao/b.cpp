
#include <cstdio>
#include <cmath>

#define orep(i, a, b) for(int i = (a); i < (b); ++i)
#define NL putchar(10)
const int maxN = 2e5+5;
int arr[maxN];

const double eps = 1e-1;
double sgn(double x) {
  return x < -eps ? -1 : (x > eps ? 1 : 0);
}

int main() {
  int n = 23333333;
  orep(i, 0, n+1) {
    long double p0 = 1.0*i/n, p1 = 1.0*(n-i)/n;
    long double h0 = -p0*log2(p0), h1 = -p1*log2(p1);
    long double ret = i*h0+(n-i)*h1;
    if (!sgn(11625907.5798-ret)) {
      printf("%.10Lf %d %d", ret, i-n+i, i) ; NL;
    }
  }
	return 0;
}
