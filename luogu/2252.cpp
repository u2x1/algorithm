#include <cstdio>
#include <cmath>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

int main() {
  int x,y; scanf("%d%d", &x, &y);
  if(x<y) { std::swap(x, y); }
  int z = x-y;
  int w = (sqrt(5)+1)/2.0*z;
  printf("%d", w!=y);
  return 0;
}
