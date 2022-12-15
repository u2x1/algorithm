#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 2e5 + 5;
long long arr[maxN];

int main() {
  int n; scanf("%d", &n);
  long long maxPrefix = 0;
  long long cur = 0;
  long long ret = 0;
  orep(i, 0, n) {
    scanf("%lld", arr+i+1); arr[i+1] += arr[i];
    maxPrefix = std::max(arr[i+1], maxPrefix);
    ret = std::max(ret, cur + maxPrefix);
    cur += arr[i+1];
  }
  printf("%lld", ret);
  return 0;
}
