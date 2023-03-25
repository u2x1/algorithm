#include <cstdio>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  int t; scanf("%d",&t);
  double pi = acos(-1);
  while(t--) {
    int a, b; scanf("%d%d", &a, &b);
    double rst = pi*a*a + 4*a*b;
    printf("%.8f\n", rst);
  }

  return 0;
}
