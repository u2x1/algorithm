#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

long long n, c;
long long curMax;
int arr[1999];
long long prefix[1999];

void dfs(const int depth, const long long curSum) {
  if (depth == -1 || curSum > c || curSum + prefix[depth] < curMax) { return; }
  const int cur = arr[depth];
  if (cur > c) {
    dfs(depth-1, curSum);
    return;
  } 
  curMax = std::max(curSum, curMax);
  if (curSum + cur <= c) { curMax = std::max(curSum+cur, curMax); }
  dfs(depth-1, curSum+cur);
  dfs(depth-1, curSum);
}

int main() {
  scanf("%lld%lld", &n, &c);
  orep(i, 0, n) { scanf("%d", arr+i); }
  prefix[0] = arr[0]; orep(i, 1, n) { prefix[i] = arr[i] + prefix[i-1]; }
  dfs(n-1, 0);
  printf("%d", curMax);
}