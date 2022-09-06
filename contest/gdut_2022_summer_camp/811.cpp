#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)
#define crep(i,a,b)  for(int i=(a); i<=(b); ++i)
#define abs(a)       ((a)<0?-(a):(a))
#define min(a,b)     ((a)<(b)?(a):(b))
#define min3(a,b,c)  min(min(a,b),c)
#define max(a,b)     ((a)>(b)?(a):(b))
#define max3(a,b,c)  max(max(a,b),c)
#define HIT          printf("entered <%s> at ln:%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);

inline const unsigned int slowRead() {
  unsigned int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

struct Work {
  unsigned int start; unsigned int end;
};

bool operator <(const Work& a, const Work& b) {
  return a.end < b.end;
}

int main() {
  int t=0;
  scanf("%d", &t);
  Work ws[t];
  orep(i, 0, t) {
    ws[i].start = slowRead();
    ws[i].end   = slowRead();
  }
  std::sort(ws, ws+t);
  unsigned int cnt=0, last=0;
  orep(i, 0, t) {
    if (ws[i].start >= last) { ++cnt; last=ws[i].end; }
  }

  printf("%d", cnt);

  return 0;
}
