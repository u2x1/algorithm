#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int n; long long arr[200001];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int p; scanf("%d%d", &n, &p);
    int arrLen = 1, tmp;
    long long health;
    arr[0] = arr[1] = 0;
    crep(i, 1, n) {
      scanf("%d", &tmp);
      if (i == p) {
        health = tmp;
        p = arrLen;
        arr[arrLen++]=0;
        continue; }
      arr[arrLen++] = tmp;
    }

//    crep(i, 0, n) { printf("%lld ", arr[i]); } NL;
    int pp=p-1; for(;pp>0;--pp) { arr[pp]+=arr[pp+1]; }
    pp=p+1; for(;pp<=n;++pp) { arr[pp]+=arr[pp-1]; }
//    crep(i, 0, n) { printf("%lld ", arr[i]); } NL;

    int l = p, r = p;
    int L=l,R=r,rmax=-0x3f3f3f3f, lmax=-0x3f3f3f3f;
    int LL=-1, RR=-1;
    while(l>=0 && r<n) {
      do {
        tmp = health + arr[r+1] + arr[l];
        if (tmp >= 0) {
          ++r;
          if (rmax < tmp) { rmax = tmp; R=r; }
        }
      } while(tmp >= 0 && r<n);
      if (r >= n) { break; }
      r=R;
      do {
        tmp = health + arr[r] + arr[l-1];
        if (tmp >= 0) {
          --l;
          if (lmax < tmp) { lmax = tmp; L=r; }
        }
      } while(tmp >= 0 && l>-1);
      if (l == -1) { break; }
      l=L;
      if (L==LL && R==RR) { break; } else { LL=L; RR=R; }
      if(health + rmax + lmax < 0) { break; }
    }
//    printf("p: %d l: %d r: %d ", p, l, r);
//    printf("lmax: %d rmax: %d ", lmax, rmax);
    printf(l==-1 || r==n ? "YES" : "NO"); NL;
  }

  return 0;
}
