#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define REDIR        freopen("data.in", "r", stdin);

unsigned long long fibs[64] = { 1, 1 };

void initfibs() {
  orep(i, 2, 64) { fibs[i] = fibs[i-1] + fibs[i-2]; }
}

inline unsigned long long read() {
  unsigned long long x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

bool judge(unsigned long long a, unsigned int p) {
  unsigned long long out = 1LL << p;
  if (a/out <= 1) { return 1; }
  return 0;
}

int main() {
  initfibs();
  int t; scanf("%d", &t);
  while(t--) {
    unsigned long long tmp = read();
    if (tmp == 0) { printf("0\n"); continue; }
    int l = 0, r = 64, mid = 32;
    while(l < r-1) {
      if (judge(tmp, mid)) { r = mid; }
      else { l = mid; }
      mid = (l+r) >> 1;
    }
    mid = judge(tmp, l) ? l : r;
    printf("%llu\n", fibs[mid]);
  }

  return 0;
}
