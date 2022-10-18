#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int arr[505][505];
bool cmp(const int a, const int b) {
  return a > b;
}

int main() {
  int n; scanf("%d", &n); --n;
  int ipt = 1;
  orep(i, 0, n) {
    crep(j, ipt, n) {
      scanf("%d", &arr[j][i]);
      arr[i][j-1] = arr[j][i];
    }
    ++ipt;
  }
  
  int max = 0;
  crep(i, 0, n) {
    std::partial_sort(arr[i], arr[i]+2, arr[i]+n, cmp);
    max = std::max(max, arr[i][1]);
  }
  printf("1\n%d", max);

  return 0;
}
