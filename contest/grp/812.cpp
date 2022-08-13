#include <cstdio>
#include <algorithm>
#include <cstring>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)
#define crep(i,a,b)  for(int i=(a); i<=(b); ++i)
#define HIT          printf("entered <%s> at ln:%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);

char a[10000]; int aLen, pos;
struct Bracket { int x; int y; } bs[5000]; int bsLen = 0;
bool operator<(const Bracket a, const Bracket b) { return a.x < b.x; } 

bool f() {
  if (pos > aLen) { return false; }
  const int curPos = pos;
  if (a[curPos] == ')') { return false; }
  else {
    while(a[pos] == '(') { ++pos; f(); }
    if (a[pos] == ')') {
      bs[bsLen].x = curPos; bs[bsLen].y = pos;
      bsLen++; ++pos; f();
    }
  }
  return true;
}

int main() {
  int t = 0; scanf("%d", &t);
  while(t--) {
    scanf("%s", a+1); aLen = strlen(a+1);
    pos = 1;
    while(f());
    std::sort(bs, bs+bsLen);
    int ret=0;
    orep(i, 0, bsLen) {
      ret = (ret*10 + bs[i].x)*10+bs[i].y;
    }
    printf("%d\n", ret);
    bsLen = 0;
  }
  return 0;
}
