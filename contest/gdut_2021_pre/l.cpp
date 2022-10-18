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


int main() {
  long long m = read();
  if (m == 1) { printf("1"); return 0; }
  long long rst = 1;
  crep(i, 2ll, m) {
    rst = (rst * i) % m;
    if (rst == 0) { printf("%lld", i); return 0; }
  }
  return 0;
}
