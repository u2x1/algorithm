#include <cstdio>

int main() {
  int cnt = 0;
  char c;
  while((c=getchar()) != '.') {
    if (c == 'a') { ++cnt; }
  }
  printf("%d", cnt);

  return 0;
}
