#include <cstdio>
#include <algorithm>
#include <cmath>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define REDIR        freopen("data.in", "r", stdin);
void otp(int k)
{
	if(!k) return;
  otp(k/10);
  putchar(k%10+48);
}

int main() {
  otp(1211);

  return 0;
}
