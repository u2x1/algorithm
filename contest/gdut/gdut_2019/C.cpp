#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define REDIR        freopen("data.in", "r", stdin);

int main() {
  int t; scanf("%d", &t); getchar();
  char c;
  while(t--) {
    int ys = 0, ns = 0, tot = 0;
    while((c = getchar()) != '\n') {
      ++tot;
      if (c == 'y' || c == 'Y') {
        ++ys;
      } else if (c == 'n' || c == 'N') {
        ++ns;
      }
    }
    const int tot_cp = tot / 2;
    if (ys >= tot_cp) {
      printf("pmznb\n");
    } else if (ns >= tot_cp) {
      printf("lyrnb\n");
    } else {
      printf("wsdd\n");
    }
  }

  return 0;
}
