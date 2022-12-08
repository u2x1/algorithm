#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i<(b); ++i)
#define NL           putchar(10);

const int maxN = 5e5+5;
int arr[maxN];

int hi(int x) {
  if (x==0) { return 0; }
  int height = 0;
  while (x!=1) {
    x>>=1; ++height;
  }
  return x << height;
}

int main() {
  int n; scanf("%d", &n);
  int xorer = 0;
  orep(i, 0, n) { scanf("%d", arr+i); xorer ^= arr[i]; }
  if (xorer) {
    const int _hi = hi(xorer);
    orep(i, 0, n) {
      if (arr[i] & _hi) {
        printf("%d %d", arr[i]-(xorer^arr[i]), i+1); NL;
        arr[i] = xorer^arr[i];
        break;
      }
    }
    orep(i, 0, n) { printf("%d ", arr[i]); }
  } else {
    printf("lose");
  }
  return 0;
}
