#include <cstdio>

long long cnt['z'+1];

int main() {
  int n;
  scanf("%d", &n); getchar();
  while(n--) {
    unsigned char c;
    while((c=getchar()) != EOF && c >= 'A') {
      ++cnt[c];
    }
    for(int i = 'a', ii = 'A'; i <= 'z'; ++i, ++ii) {
      while (cnt[i]) { putchar(i); --cnt[i]; }
      while (cnt[ii]) { putchar(ii); --cnt[ii];}
    } putchar(10);
  }

  return 0;
}
