#include <cstdio>
#include <cstring>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int arr[105], n;

bool check(const int k) {
  const int largest = k;
  int target = -1;
  orep(j, 0, n) {
    if (arr[j] > largest) { break; }
    target = j;
  }
  if (target == -1) { return 0; }
  int round = 1;
  while(target != -1) {
    if (arr[target] + largest*round-(round-1)*round/2 > k-round) {
      return false;
    }
    --target;
    ++round;
  }
  return true;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
   scanf("%d", &n);
    orep(i, 0, n) { scanf("%d", arr+i); }
    std::sort(arr, arr+n);
    int l = 0, r = n, mid = (l+r) >> 1;
    while(l < r-1) {
      if (check(mid)) { l = mid; }
      else { r = mid - 1; }
      mid = (l+r) >> 1;
    }
    printf("%d", check(r) ? r : l); NL;

  }


  return 0;
}
