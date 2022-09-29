#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int cnt[101];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n, c; scanf("%d%d", &n, &c);
    memset(cnt, 0, sizeof(cnt));
    int tmp, cost=0;
    orep(i, 0, n) { scanf("%d", &tmp); ++cnt[tmp]; }
    orep(i, 0, 101) {
      cost += cnt[i] > c ? c : cnt[i];
    }
    printf("%d", cost); NL;
  }

  return 0;
}
