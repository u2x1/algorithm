#include <cstdio>
#include <climits>


#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

#define max(a,b) a>b?a:b

int l, k;
int arr[100005];

long long judge(const long long line) {
  long long cur = 0; long long cK = 0;
  orep(i, 0, l) {
    cur = max(cur+arr[i], 0);
    if (cur >= line) { cur = 0; ++cK;} 
  }
  return cK;
}

int main() {
  scanf("%d%d",  &l, &k);
  orep(i, 0, l) { scanf("%d", arr+i); }
  long long l=1, r=1e18, mid;
  long long ans1, ans2=-1;
  while(l<=r) {
    mid = (l+r)>>1;
    const long long rst = judge(mid);
    if (rst > k) { l = mid + 1;}
    else if (rst < k) { r = mid - 1;}
    else { ans2 = mid; l = mid + 1; }
  }
  if (ans2 == -1) { printf("-1"); return 0; }
  l = 1; r=ans2;
  while(l<=r) {
    mid = (l+r)>>1;
    const long long rst = judge(mid);
    if (rst > k) { l = mid + 1;}
    else if (rst < k) { r = mid - 1;}
    else { ans1 = mid; r = mid - 1; }
  }
  printf("%lld %lld", ans1, ans2);
  return 0;
}