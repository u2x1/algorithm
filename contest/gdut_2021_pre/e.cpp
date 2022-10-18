#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);


int arr[100005];

int main() {
  int n, k; scanf("%d%d", &n, &k);
  if (n==1) { printf("YES"); return 0;}
  orep(i, 0, n) { scanf("%d", arr+i); }
  std::sort(arr, arr+n);

  printf(arr[n-1] - arr[n-2] >= k ? "YES" : "NO");

  return 0;
}
