#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int cnt['z'+1] = {}; memset(cnt, 0, sizeof(cnt));
    int n; scanf("%d", &n); n*=2;
    char str[n+1];
    orep(j, 0, 2) {
      scanf("%s", str);
      orep(i, 0, n) { ++cnt[str[i]]; }
    }
    bool flag = 1;
    crep(i, 'a', 'z') {
      if (cnt[i] % 2) {
        flag = 0; break;
      }
    }
    printf(flag ? "YES" : "NO"); NL;
  }
  return 0;
}
