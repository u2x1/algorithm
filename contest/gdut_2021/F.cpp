#include <cstdio>
#include <vector>

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


int main() {
  int n;
  scanf("%d ", &n);
  std::vector<int> os, ss, us;
  orep(i, 0, n) {
    const char c = getchar();
    if (c == 'o') { os.push_back(i); }
    else if (c == 's') { ss.push_back(i); }
    else if (c == 'u') { us.push_back(i); }
  }
  int cnt = 0;
  orep(i, 0, os.size()) {
    const int oPos = os[i];
    orep(j, 0, ss.size()) {
      const int sPos = ss[j];
      if (sPos < oPos) { continue; }
      orep(k, 0, us.size()) {
        const int uPos = us[k];
        if (uPos < sPos) { continue; }
        ++cnt;
      }
    }
  }

  printf("%d", cnt);

  return 0;
}
