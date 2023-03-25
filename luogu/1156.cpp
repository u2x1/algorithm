#include <iostream>
#include <cstring>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

struct st { int t, f, h; };
bool operator<(const st a, const st b) { return a.t < b.t; }
const int maxN = 2e5+5;
st arr[maxN];
int dp[105][305];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  memset(dp, -0x3f, sizeof dp);
  int d, g; std::cin >> d >> g;
  orep(i, 1, g+1) {
    std::cin >> arr[i].t >> arr[i].f >> arr[i].h;
  }
  std::sort(arr+1, arr+g+1);
  dp[0][0] = 10;
  int mx = 0; int last = 0;
  orep(i, 1, g+1) {
    const int diff = arr[i].t - last;
    orep(j, 0, 105) {
      if (dp[i-1][j] >= diff) {
        // {std::cout << arr[i].t << "," << j << ": "<< dp[i-1][j]; NL;}
        // {std::cout << diff; NL;}
        if (j+arr[i].h >= d) { std::cout << arr[i].t; return 0; }
        if (j >= d) { std::cout << arr[i].t; return 0; }
        dp[i][j+arr[i].h] = dp[i-1][j] - diff;
        dp[i][j] = std::max(dp[i][j], dp[i-1][j] - diff + arr[i].f);
        // {std::cout << arr[i].t << "," << j << ": "<< dp[i][j]; NL;}
        // {std::cout << arr[i].t << "," << j+arr[i].h << ": "<< dp[i][j+arr[i].h]; NL;}
        // {std::cout << "mx: "<< mx; NL;}
      }
      mx = std::max(mx, arr[i].t+dp[i][j]);
    }
    last = arr[i].t;
  }
  std::cout << mx;
  return 0;
}
