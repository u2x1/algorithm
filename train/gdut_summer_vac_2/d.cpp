#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 5e5+5;
int dp[maxN];
int dp2[maxN];
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n = 0;
  while(std::cin >> arr[n++]);
  n--;
  int len = 0;
  orep(i, 0, n) {
    if (!len || arr[i] <= dp[len-1]) {
      dp[len++] = arr[i];
    } else {
      int* it = std::upper_bound(dp, dp+len, arr[i], std::greater<int>());
      *it = arr[i];
    }
  }
  std::cout << len << NL;
  int len2 = 0;
  orep(i, 0, n) {
    if (!len2 || arr[i] > dp2[len2-1]) {
      dp2[len2++] = arr[i];
    } else {
      int* it = std::lower_bound(dp2, dp2+len2, arr[i]);
      *it = arr[i];
    }
  }
  std::cout << len2;

  return 0;
}
