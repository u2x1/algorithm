#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    int arr[n];
    orep(i, 0, n) { scanf("%d", arr+i); }
    std::sort(arr, arr+n);
    int mmin = 0x3f3f3f3f;
    orep(i, 1, n-1) {
      mmin = std::min(mmin, arr[i+1]-arr[i-1]);
    }
    printf("%d", mmin);
    if (t) { NL; }
  }


  return 0;
}
