#include <cstdio>
#include <algorithm>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

constexpr int maxN = 1e6+10;

int dp1[maxN], dp2[maxN];
struct K { int id, num, rk; } arr[maxN], sortedArr[maxN];
bool cmpInc(const K &a, const K &b) { return a.num < b.num; }
bool cmpId(const K &a, const K &b) { return a.id < b.id; }

void count(const int n, int &cnt1, int &cnt2) {
  orep(i, 0, n) {
    dp1[i] = dp2[i] = 1;
  }
  orep(i, 0, n) {
    const int rkDn = arr[i].rk-1, rkUp = arr[i].rk+1;
    if (rkDn > -1 && sortedArr[rkDn].id < i) {
      dp1[i] = dp1[sortedArr[rkDn].id]+1;
      cnt1 = std::max(cnt1, dp1[i]);
    } if (rkUp < n && sortedArr[rkUp].id < i) {
      dp2[i] = dp2[sortedArr[rkUp].id]+1;
      cnt2 = std::max(cnt2, dp2[i]);
    }
  }
}

int main() {
  int n; scanf("%d", &n);
  if (n==1) { printf("0"); return 0; }
  orep(i, 0, n) {
    scanf("%d", &arr[i].num);
    arr[i].id = i;
  }
  memcpy(sortedArr, arr, n*sizeof(K));
  std::sort(sortedArr, sortedArr+n, cmpInc);
  orep(i, 0, n) {
    sortedArr[i].rk = i;
    arr[sortedArr[i].id].rk = i;
  }

  int cnt1 = 0, cnt2 = 0;
  count(n, cnt1, cnt2);
  printf("%d", n - std::max(cnt1, cnt2));

  return 0;
}
