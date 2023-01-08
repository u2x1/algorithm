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
#define REDIR        freopen("data.in", "r", stdin);

int ret, n, *a;
bool *used, *left;
char *out;

inline const int slowRead() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

void dfs(const int p, const int accu) {
  if (p == n) {
    if (ret >= accu) { return; }
    orep(i, 0, n) { out[i] = left[i] ? '1' : '0'; }
//    orep(i, 0, n) { putchar(out[i]); } NL;
    ret = accu;
    return;
  }
  if (used[p]) { dfs(p+1, accu); return; }
  const int cur = a[p];

  used[p] = left[p] = 1;
  for (int i = p+1; i < n; i+=2) {
    if (used[i]) { continue; }
    used[i] = 1;
    dfs(p+1, accu+abs(cur-a[i]));
    used[i] = 0;
  }
  used[p] = left[p] = 0;
}

int main() {
  REDIR;
  scanf("%d", &n); n*=2;
  a = new int[n];
  used = new bool[n]; left = new bool[n];
  out = new char[n];

  orep(i, 0, n) { a[i] = slowRead(); }
  memset(used, 0, n*sizeof(bool));
  memset(left, 0, n*sizeof(bool));

  dfs(0, 0);
  orep(i, 0, n) { putchar(out[i]); }
  return 0;
}
