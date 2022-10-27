/*
  x = 0.123 123 123...
        ^^^ ^^^ ^^^
    {1} x*1000 = 123.123123...
    {2} x*999  = 123.123123... - x
               = 123.123123... - 0.123123...
               = 123
    {3} x      = 123/999
  
  x = 0.111 1234 1234...
            ^^^^ ^^^^
    {1} 令y = 0.12341234...，则x=(y+111)/1000
    {2} 由上述求法得y=1234/9999
    {3} x = ({y=1234/9999}+111)/1000
          = (1234+111*9999)/9999000

    {1} x*1000-111 = 0.12341234...
    {2} (x*1000-111)*10000 = 1234.12341234...
    {3} (x*1000-111)*9999 = 1234
    {4} x = (1234/9999+111)/1000
          = (1234+111*9999)/9999000
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

#define inc(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define dec(i,a,b)  for(auto i=(b); i<=(b); ++i)
#define NL           putchar(10);

const double eps = 1e-8;

void reduce(long long &a, long long &b) {
  long long cd = std::__gcd(a, b);
  while(cd != 1) {
    a/=cd; b/=cd;
    cd = std::__gcd(a, b);
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    double x; int l, r;
    scanf("%lf%d%d", &x, &l, &r);

    if (((x * pow(10, 6))) == 0) {
      printf("0"); return 0;
    }

    bool neg = x < 0;
    if (neg) { x = -x; }

    long long intpart = (long long)x;
    x -= intpart;

    long long up=1, dn=1;
    if (l == 1) {
      up = x*pow(10,r-l+1) + eps;
      dn = pow(10,r-l+1) - 1;
    } else {
      long long notrepeat = x * pow(10, l-1) + eps;
      long long notrepeatLen = pow(10, l-1);
      x *= notrepeatLen;  x -= (long long)x;
      up = (long long)(x*pow(10, r-l+1) + eps)
              + notrepeat * (pow(10, r-l+1)-1);
      dn = (pow(10, r-l+1)-1) * notrepeatLen;
    }
    up += intpart * dn;

    reduce(up, dn);
    if (neg) { printf("-"); }
    if (dn == 1) { printf("%lld", up); }
    else { printf("%lld/%lld", up, dn); }
    NL;
  }
  return 0;
}
