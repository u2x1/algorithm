#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define REDIR        freopen("data.in", "r", stdin);

int cmp(char a, char b) {
  if (a == b) { return 0; }
  if (  (a == 'S' && b == 'J')
     || (a == 'J' && b == 'B')
     || (a == 'B' && b == 'S')) {
    return 1;
  }
  return -1;
}

int main() {
  char a=getchar(), b=getchar(); getchar();
  char c=getchar();

  int rst1 = cmp(a, c), rst2 = cmp(b, c);
  if (rst1 == 1 || rst2 == 1) {
    printf("pmznb");
  } else if (rst1 == 0 || rst2 == 0) {
    printf("lyrnb");
  } else {
    printf("ljrnb");
  }

  return 0;
}
