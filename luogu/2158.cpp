#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i<(b); ++i)
#define NL           putchar(10);

const int maxN = 4e4+5;
int phi[maxN];

int main() {
  int n; scanf("%d", &n);
  orep(i, 2, n+1) { phi[i] = i; }
  for(int i = 2; i <= n; ++i) {
    if (phi[i]==i) {
      for(int j = i; j <= n; j+=i) {
        phi[j] = phi[j]*(i-1)/i;
      }
    }
  }
  int rst = 0; orep(i, 2, n) { rst += phi[i]; }
  printf("%d", n==1?0:rst*2+3);
  return 0;
}
