#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int l, k;

int judge(int *arr, int line) {
  long long cur = 0; int cK = 0;
  orep(i, 0, l) {
    cur += arr[i];
    if (cur >= line) {
      cur = 0;
      ++cK;
      if (cK > k) { return 1; }
    } else if (cur < 0) { cur = 0; }
  }
  cK += cur > 0;
  if (cK < k) { return -1; }
  return 0;
}

int main() {
  scanf("%d%d",  &l, &k);
  int arr[l];
  orep(i, 0, l) { scanf("%d", arr+i); }
  int l=0, r=0x3f3f3f3f, mid=(l+r)/2;
  while(1) {
    const int flag = judge(arr, mid);
    if (flag == -1) {
      r = mid;
    } else if (flag == 1) {
      l = mid; 
    } else {
      break;
    }
    mid = (l+r) / 2;
  }
  l=mid, r=mid;
  while(!judge(arr, --l)); ++l;
  while(!judge(arr, ++r)); --r;
  printf("%d %d", l, r);
  return 0;
}
