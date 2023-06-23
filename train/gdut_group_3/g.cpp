#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 5e3+5;
int arr[maxN];
std::string ss[maxN];
std::pair<int, int> mx[maxN][20];
int dp[maxN];

int n, w;

int query(const int l, const int r) {
  const int k = std::__lg(r-l);
  return std::max(mx[l][k], mx[r-(1<<k)][k]).first;
}

int ls[maxN];

void ans(const int h) {
  memset(dp, 0x3f, sizeof(dp));
  orep(i, 0, n) {
    orep(k, 1, h+1) {
      const int l = std::max(0, i-k+1);
      dp[i] = std::min(dp[i], (l ? dp[l-1] : 0) + query(l, i+1));
    }
  }
}

bool check(const int h) {
  memset(dp, 0x3f, sizeof(dp));
  memset(ls, 0, sizeof(ls));
  orep(i, 0, n) {
    orep(k, 1, h+1) {
      const int l = std::max(0, i-k+1);
      const int a = (l ? dp[l-1] : 0) + query(l, i+1);
      if (dp[i] > a) { ls[i] = l; dp[i] = a; }
    }
  }
  return dp[n-1] <= w;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> w;
  orep(i, 0, n) {
    std::cin >> ss[i];
    mx[i][0] = { ss[i].size(), i };
  }
  orep(k, 1, 20) {
    for(int i = 0; i+(1<<k)-1 < n; ++i) {
      mx[i][k] = std::max(mx[i][k-1], mx[i+(1<<(k-1))][k-1]);
    }
  }
  int l = -1, r = 5001;
  while(l < r-1) {
    const int mid = (l+r) >> 1;
    if (check(mid)) { r = mid; }
    else { l = mid; }
  }
  std::cout << r;
  check(r);
  std::vector<int> ret1 { n-1 };
  NL; orep(i, 0, n) { std::cout << ls[i] << " "; } NL;
  int i = n-1;
  for(; ls[i] != 0; i = ls[i]-1) {
    ret1.push_back(i-ls[i]+1);
  }
  ret1.push_back(i);
  for(const auto x : ret1) { std::cout << x << " "; } NL;
  std::cout << ret1.size();

  return 0;
}
