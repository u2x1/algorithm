#include <cstdio>
#include <cstring>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; char ch[100005]; scanf("%d%s", &n, ch);
    int last = 2;
    int cnt[3]; memset(cnt, 0, sizeof(cnt));
    orep(i, 0, n) {
      const int idx = ch[i] - '0';
      if (idx != last) {
        ++cnt[last];
        last = idx;
      }
    }
    ++cnt[last];
    printf("%d", std::min(cnt[0], cnt[1])); NL;
  }

  return 0;
}
