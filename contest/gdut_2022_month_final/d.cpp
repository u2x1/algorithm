#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int gcd(int a, int b) {
  if (a < b) { std::swap(a, b); }
  return (!b) ? a : gcd(b, a%b);
}

const int maxN = 1e6+5;
int arr[maxN];

int main() {
  int n; scanf("%d", &n);
  orep(i, 0, n) { scanf("%d", arr+i); }
  std::sort(arr, arr+n);
  int last = 0;
  orep(i, 1, n) {
    last = gcd(arr[i]-arr[i-1], last);
  }
  printf("%d", !last ? n : (arr[n-1]-arr[0]) / last + 1);
  return 0;
}
