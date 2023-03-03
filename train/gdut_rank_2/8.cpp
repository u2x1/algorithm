#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
char s[maxN];

int main() {
  int n; char c; scanf("%d %c ", &n, &c);
  
  char ch; int len = 0;
  while((ch=getchar()) != EOF && (ch!='\n')) {
    s[len++] = ch;
  }
  s[len] = 0;
  if (n <= len) {
    printf("%s",s+len-n);
  } else {
    orep(i, 0, n-len) {
      putchar(c);
    }
    printf("%s", s);
  }

  return 0;
}
