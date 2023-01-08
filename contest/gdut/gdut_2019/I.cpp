#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define REDIR        freopen("data.in", "r", stdin);

int main() {
  int t; scanf("%d", &t);
  int p; char c;
  while(t--) {
    scanf("%d", &p); getchar();
    char tmp;
    while((tmp = getchar()) >= '0' && tmp <= '9') {
      c = tmp;
    }
    const int i = c - '0';
    if (i%2) {
      printf("%d\n", p-1);
    } else {
      printf("1\n");
    }
  }

  return 0;
}
