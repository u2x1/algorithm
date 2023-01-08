#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int maxN = 1000005;
bool arr[maxN];
int leftsum[maxN], rightsum[maxN];
int cnt = 1;

int main() {
  int n; scanf("%d ", &n);
  int ii = 0; while(ii++ < n && getchar() == '0');
  if (ii == n) { printf("0"); return 0; }
  int end = 0; arr[0] = 1;
  crep(j, 1, n-ii) {
    if(getchar() == '1') { arr[j] = 1; ++cnt; end = j; }
  }

  leftsum[0] = 1;
  crep(i, 1, end) {
    leftsum[i] = leftsum[i-1] + arr[i];
  }

  rightsum[end] = 1;
  for(int i = end-1; i > 0; --i) {
    rightsum[i] = rightsum[i+1] + arr[i];
  }

  long long ret = 0;
  orep(i, 1, end) {
    if (!arr[i]) {
      ret += std::min(leftsum[i], rightsum[i]);
    }
  }
  printf("%lld", ret);
  return 0;
}
