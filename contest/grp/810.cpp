#include <cstdio>

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

inline int read() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

int n, s;

bool check(int *arr, const int hp) {
  const int end = n-hp;
  crep(i, 0, end) {
    if (arr[i+hp] - arr[i] >= s) { return 1; }
  }
  return 0;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &s);
    int arr[n+1] = {0};
    crep(i, 1, n) { arr[i] = arr[i-1] + read(); }
    if (arr[n] < s) { printf("0\n"); continue; }

    int l=1, r=n, mid=(r+l)>>1;
    while(l+1<r) {
      if (check(arr, mid)) { r=mid; }
      else { l=mid; }
      mid = (l+r)>>1;
    }
    printf("%d\n", check(arr,l) ? l : r);
  }
  return 0;
}
