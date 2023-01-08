#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int calHeight(long long x) {
  if (x == 0) { return 1; }
  int ret = 0;
  while(x) { x /= 10ll; ++ret; }
  return ret;
}

long long construct(bool size, int height) {
  long long ret = size ? 9 : 1;
  --height;
  while(height--) {
    ret = ret * 10 + (size ? 9 : 0);
  }
  return ret;
}

long long sameHeightAns(long long l, long long r, int height) {
  while(l < r && l%height) { ++l; }
  while(r > l && r%height) { --r; }
  if (l == r && (l%height)) { return 0; }
  return (r-l)/height+1;
}

long long ans(long long  l, long long r) {
  int leftHeight = calHeight(l), rightHeight = calHeight(r);
  if (leftHeight == rightHeight) {
    return sameHeightAns(l, r, leftHeight);
  } else {
    int leftBound = construct(1, leftHeight);
    int rightBound = construct(0, rightHeight);
    long long ret = sameHeightAns(l, leftBound, leftHeight) 
                  + sameHeightAns(rightBound, r, rightHeight);
    ++leftHeight;
    long long ll = construct(0, leftHeight), rr = construct(1, leftHeight);
    while(leftHeight < rightHeight) {
      ret += sameHeightAns(ll, rr, leftHeight);
      ll *= 10; rr *= 10; rr += 9;
      ++leftHeight;
    }
    return ret;
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    long long l, r; scanf("%lld%lld", &l, &r);
    printf("%lld", ans(l, r)); NL; 
  }

  return 0;
}
