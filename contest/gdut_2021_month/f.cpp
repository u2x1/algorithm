#include <cstdio>
#include <set>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

inline int read() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

int sum[400005], lpos[400005];

int main() {
  int m; scanf("%d", &m);
  crep(i, 0, m) { lpos[i] = -1; }
  int rmost = -1, corAns = -1;
  crep(i, 1, m) {
    int tmp = read() % m;
    sum[i] = (sum[i-1] + tmp) % m;
    const int pos = lpos[sum[i]];
    if (~pos) {
      if (pos+1 >= rmost) {
        rmost = pos+1;
        corAns = i;
      }
    } else if (sum[i] == 0) {
      rmost = 1;
      corAns = i;
    }
    lpos[sum[i]] = i;
  }
  if (m == 1) {
    rmost = corAns = 1;
  }
  if (rmost != -1) {
    printf("%d %d", rmost, corAns);
  } else {
    printf("-1");
  }

  return 0;
}
