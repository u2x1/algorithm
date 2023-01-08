#include <cstdio>
#include <cstring>
#include <algorithm>

#define NL          putchar(10);
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)

const int maxN = 53;

char arr[maxN];
int cnt[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%s", arr); memset(cnt, 0, sizeof(cnt));
    const int len = strlen(arr);
    orep(i, 0, len) {
      cnt[arr[i]-'a']++;
    }
    orep(i, 0, 1+'z'-'a') {
      orep(j, 0, cnt[i]) {
        putchar('a'+i);
      }
    } NL;
  }
  return 0;
}
