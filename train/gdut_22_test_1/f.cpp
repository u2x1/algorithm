#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 5e3+5;

struct st { long long x, y, t, v; }arr[maxN];
long long dp[maxN];
bool operator<(const st a, const st b) { return a.t < b.t; }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  arr[0] = { 0, 0, 0, 0 };
  orep(i, 1, n+1) {
    std::cin >> arr[i].x >> arr[i].y >> arr[i].t >> arr[i].v;
  }
  const int INF = 0x3f3f3f3f;
  std::sort(arr, arr+n+1);


  return 0;
}
