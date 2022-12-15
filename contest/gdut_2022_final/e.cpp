#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 2e5;
char str[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    long long k; scanf("%s%lld", str, &k);
    int last = str[strlen(str)-1] - '0';
    printf("%d", last); NL;
  }
  return 0;
}
