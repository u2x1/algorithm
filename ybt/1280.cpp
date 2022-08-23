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
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);

inline int read() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

int r, c;
int endRet;

int f(int* const arr, bool* const used, int* const save, const int x, const int y, const int last) {
  if (x < 0 || x > r || y < 0 || y > c) { return 0; }
  PTD(x); PTD(y);
  bool* curFlag = used + x*c + y;
  if (*curFlag) { return 0; }
  const int cur = *(arr + x*c + y);
  if (last <= cur) { return 0; }
  int* const saved = save + x*c + y;
  if (*saved) { printf(" saved hit: %d\n", *saved); return *saved; }
  *curFlag = 1;
  const int a = f(arr, used, save, x, y+1, cur);
  const int b = f(arr, used, save, x-1, y, cur);
  const int c = f(arr, used, save, x, y-1, cur);
  const int d = f(arr, used, save, x+1, y, cur);
  *curFlag = 0;
  const int ret = max(max3(a,b,c),d) + cur;
  *saved = ret;
  printf("return hit %d\n", ret);
  if (ret > endRet) { endRet = ret; }
  return max(max3(a,b,c),d) + cur;
}

int main() {
  scanf("%d%d", &r, &c);
  int a[r][c]={};
  bool used[r][c]={};
  int save[r][c]={};
  memset(save, 0, sizeof(save));
  orep(i, 0, r) {
    orep(j, 0, c) {
      scanf("%d", &a[i][j]);
    }
  }
  orep(i, 0, r) {
    orep(j, 0, c) {
      f((int*)a, (bool*)used, (int*)save, i, j, 0x3f);
    }
  }

  printf("%d", endRet);

  return 0;
}
