#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];
int m,n, r,c;
bool check(const int x, const int y) {
  if (x < 1 || x > m || y < 1 || y > n) {
    return 0;
  }
  return 1;
}

int main() {
  scanf("%d%d%d%d", &m, &n, &r, &c);
  printf("%d", check(r-1, c) + check(r+1, c) + check(r, c-1) + check(r, c+1));
  return 0;
}
