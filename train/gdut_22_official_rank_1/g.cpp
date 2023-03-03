#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e6+5;
int arr[maxN];
long long sum[maxN];
long long rst[maxN]; int cnt;

long long leftsum[maxN], rightsum[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k, m; std::cin >> n >> k >> m;
  long long allsum = 0;
  orep(i, 1, 1+n) {
    std::cin >> arr[i];
    allsum += arr[i];
  }

  orep(i, 1, k) {
    leftsum[i] = leftsum[i-1] + arr[i];
    std::cout << "leftsum " << i <<leftsum[i]; NL;
  } int leftcnt = k-1;
  for(int i = n, j = 1; i > k; --i, ++j) {
    rightsum[j] = rightsum[j-1] + arr[i];
    std::cout << "rightsum " << j <<rightsum[j]; NL;
  } int rightcnt = n-leftcnt-1;
  std::sort(leftsum, leftsum+leftcnt, std::greater<int>());
  std::sort(rightsum, rightsum+rightcnt, std::greater<int>());

  int i = 1, j = 1;
  int leftcur = leftcnt, rightcur = rightcnt;
  while(leftcur ) {
    if (leftsum[i] > rightsum[j]) {
      if (m <= rightcur) { std::cout << allsum - (leftsum[i]+rightsum[j+m-1]); return 0; }
      else { leftcur--; m -= rightcur; ++i; }
    } else if (leftsum[i] < rightsum[j]) {
      if (m <= leftcur) { std::cout << allsum - (leftsum[i+m-1]+rightsum[j]); return 0; }
      else { rightcur--; m -= leftcur; ++j; }
    } else {
      int ii = i+1, jj = j+1;
      while(ii <= leftcnt && jj <= rightcnt) {
        if (leftsum[ii] < rightsum[jj]) { ++jj; }
        else if ()

      }
    }
  }

  return 0;
}
