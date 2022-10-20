#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int maxN = 2e5+5;
int h[maxN], s[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    orep(i, 0, n) { scanf("%d", h+i); }
    int maxSpell=-1, itspos=-1;
    orep(i, 0, n) {
      scanf("%d", s+i);
      if(s[i] > maxSpell) { maxSpell = s[i]; itspos = i; }
    }
    long long ret = 0;
    orep(i, 0, n) {
      ret += h[i] + ((i == itspos) ? 0 : s[i]);
    }
    printf("%lld", ret); NL;
  }
  return 0;
}
