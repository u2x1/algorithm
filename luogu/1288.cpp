#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

int main() {
  int n; scanf("%d", &n);
  orep(i, 0, n) { scanf("%d", arr + i); }
  orep(i, 0, n) {
    if (!arr[i] ) {
      if (i%2) { printf("YES"); return 0; }
      break;
    }
  }
  for(int i = n-1; i > -1; --i) {
    if (!arr[i]) {
      if ((n-1-i)%2) { printf("YES"); return 0; }
      break;
    }
  }
  printf("NO");
  return 0;
}
