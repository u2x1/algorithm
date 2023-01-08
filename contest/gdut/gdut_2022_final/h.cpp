#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
const int mod = 1e9+7;
int arr[maxN], aCnt, neg[maxN], bCnt;
int zero;

int main() {
  int n, k; scanf("%d%d", &n, &k);
  orep(i, 0, n) {
    int tmp;
    scanf("%d", &tmp);
    if (tmp > 0) { arr[aCnt++] = tmp; }
    else if (tmp < 0) { neg[bCnt++] = tmp; }
    else { ++zero; }
  }
  std::sort(arr, arr+aCnt);
  std::sort(neg, neg+bCnt);
  long long rst = 1;
  int bPos=0; --aCnt;
  while(k) {
    int rstA = -99999999, rstB = -99999999;
    if((bPos+1)<bCnt && k>1) { // k == 1 || bPos == bCnt-1
      if (neg[bPos] * neg[bPos+1] < arr[aCnt])
      rstA = (rst * (neg[bPos] * neg[bPos+1]) % mod) % mod;
      k-=2;
      bPos += 2;
    }
    if (aCnt > -1 && k;) {
      rst = (rst * arr[aCnt]) % mod;
      --k; --aCnt;
    }
    if (rstA < rstB) 
  }
  
  if (k) {
    if (zero) {
      rst = 0;
    } else if (bPos == bCnt-1){
      rst = -(rst * (-neg[bPos]) % mod);
    }
  }
  printf("%lld", rst);
  return 0;
}
