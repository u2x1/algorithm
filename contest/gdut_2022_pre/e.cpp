#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int n; long long k;
int dm[200005], ht[200005];
int inf = 1e9+1;

bool check(int x) {
  long long got = 0;
  orep(i, 0, n) {
    if (x >= ht[i]) {
      got += dm[i];
    } else {
      --x;
    }
    if (k <= got) { return 1; }
  }
  return 0;
}

int main() {
  scanf("%d%lld", &n, &k);
  orep(i, 0, n) { scanf("%d", dm+i); }
  orep(i, 0, n) { scanf("%d", ht+i); }
  int l = 1, r = inf;
  while(l < r) {
    const int mid = (l+r) >> 1;
    if (check(mid)) { r = mid; }
    else { l = mid + 1; }
  }
  printf("%d", l);

  return 0;
}
