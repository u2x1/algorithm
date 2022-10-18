#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int arr[400];

int main() {
  int n;
  scanf("%d", &n);
  orep(i, 0, n) {
    scanf("%d", arr+i);
  }

  std::sort(arr, arr+n);

  long long rst = arr[n-1]*arr[n-1];
  int l = 0, r = n-1;
  bool flag = 0;
  while(l != r) {
    rst += (arr[l] - arr[r]) * (arr[l] - arr[r]);
    if (flag) {
      ++l;
    } else {
      --r;
    }
    flag = !flag;
  }

  printf("%lld", rst);

  return 0;
}
