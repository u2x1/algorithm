#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define inc(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define dec(i,a,b)  for(auto i=(b); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    char x[1000]; int l, r;
    scanf("%s%d%d", &x, &l, &r);
    int i = 0; bool neg = 0;
    if (x[i] == '-') { neg = 1; ++i; }

    int len = strlen(x);
    long long intpart = 0, litpart = 0, reppart = 0;
    long long ten = 1, nine = 1;

    for(; i < len && x[i] != '.'; ++i) {
      intpart = intpart*10 + (x[i] - '0');
    }
    for(int j = 1; j < l && i+j < len; ++j) {
      litpart = litpart*10 + (x[i+j] - '0');
      ten*=10;
    }
    for(int j = l; j <= r && i+j < len; ++j) {
      reppart = reppart*10 + (x[i+j] - '0');
      nine*=10;
    }
    --nine;
    long long dn = nine*ten;
    long long up = intpart*dn + (reppart + litpart*nine);
    long long cd = std::__gcd(up, dn);
    if (!cd) { printf("0"); return 0; }
    dn/=cd; up/=cd;
    printf(neg?"-":"");
    if (dn == 1) { printf("%lld", up); }
    else { printf("%lld/%lld", up, dn); }
    NL;
  }
  return 0;
}
