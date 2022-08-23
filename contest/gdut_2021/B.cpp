#include <cstdio>
#include <cstring>

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

int k,len, cnt['z'+1];
char str[99999];

void reset() { memset(cnt, 0, sizeof(cnt)); }

bool judge(const int n) {
  orep(i, 0, n) {
    ++cnt[str[i]];
    if (cnt[str[i]] >= k) { reset(); return true; }
  }
  int l = 0, r = n;
  while(r < len) {
    --cnt[str[l++]];
    ++cnt[str[r++]];
    if (cnt[str[r-1]] >= k) { reset(); return true; }
  }
  reset();
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s%d", str, &k);
    len = strlen(str);
    int l=1, r=len, mid=(l+r)/2;
    while(l<r-1) {
      if (judge(mid)) { r = mid; }
      else { l = mid; }
      mid=(l+r)/2;
    }
    if (judge(r)) { printf("%d", r); }
    else if (judge(l)) { printf("%d", l); }
    else { printf("-1"); }
    putchar(10);
  }

  return 0;
}
