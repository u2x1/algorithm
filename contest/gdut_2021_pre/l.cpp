#include <cstdio>
#include <cmath>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

inline long long read() {
  long long x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

long long gcd(long long a, long long b) {
  if (a < b) { std::swap(a, b); }
  return b ? gcd(b, a%b) : a;
}

int main() {
  long long m = read();
  if (m == 1) { printf("1"); return 0; }
  long long bound = 2 * std::sqrt(m) + 0.5;
  crep(i, 2ll, bound) {
    m /= gcd(m, i);
    if (m == 1) { printf("%lld", i); return 0; }
  }
  printf("%lld", m);
  return 0;
}
