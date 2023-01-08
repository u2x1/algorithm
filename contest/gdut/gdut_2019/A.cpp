#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define REDIR        freopen("data.in", "r", stdin);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    int mx = -1;
    int tmp;
    while(n--) {
      scanf("%d", &tmp);
      if (mx < tmp) { mx = tmp; }
    }
    printf("%d\n", mx);
  }

  return 0;
}
