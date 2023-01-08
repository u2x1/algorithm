#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int mod = 1e9+7;

int c[5005][5005];

void init() {
  orep(i, 0, 5005) {
    c[0][i] = 0;
    c[i][0] = 1;
  }
  orep(i, 1, 5005) {
    crep(j, 1, i) {
      c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    }
  }
}


int main() {
  init();
  int t;  scanf("%d", &t);
  while(t--) {
    int k, m; scanf("%d%d", &k, &m);
    orep(i, 0, k) {
      int tmp; scanf("%d", &tmp);
      m -= tmp;
    }
    if (m < 0) { printf("ShuanQ!"); NL; continue; }
    printf("oh yeah haha i can make it!"); NL;
    printf("%d", c[m+k-1][k-1]); NL;
  }
  return 0;
}
