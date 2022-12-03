#include <cstdio>
#include <cstring>

#define cfor(i,a,b,step)  for(auto i=(a); i!=(b); i+=step)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

char s1[1000], s2[1000];

int main() {
  scanf("%s%s", s1, s2);
  printf("%d", strcmp(s1,s2));
  return 0;
}