#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
int dp[2];
const int mod = 19940417;
struct pt { int x, y; } pts[maxN];
bool operator< (const pt a, const pt b) { return a.x < b.x; }

//int two[maxN];

int ksm(int e) {
  long long ret = 1; long long a = 2;
  while(e) {
    if (e&1) { ret = a*ret % mod; }
    a = a*a % mod; e >>= 1;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
//  two[0] = 1;
//  orep(i, 1, maxN) { two[i] = two[i-1] * 2 % mod; }
  int n, k; std::cin >> n >> k;
  pts[k+1] = { n, 0 };
  orep(i, 1, k+1) {
    std::cin >> pts[i].x >> pts[i].y;
  }
  std::sort(pts, pts+k+2);
  dp[1] = 1;
  int mx = 0;
  orep(i, 1, k+2) {
    const pt &l = pts[i-1], &r = pts[i];
    if (l.x == r.x) { continue; }
    if (abs(l.x-r.x) < abs(l.y-r.y) || (abs(l.x-r.x) + abs(l.y-r.y)) & 1) { std::cout << "0 0"; return 0; }

    const int dp0 = dp[0], dp1 = dp[1];
    const int zl = l.x+l.y, zr = r.x-r.y;
    const int zero = (zr < zl ? 0 : (zr-zl)/2+1-(r.y==0)-(l.y==0));

    if (zero == 0) {
      if (abs(l.x-r.x) != abs(l.y-r.y)) {
        dp[0] = dp1; dp[1] = 0;
      } else {
        if (l.y < r.y) { dp[0] = 0; }
        else { dp[0] += dp1; dp[1] = 0; }
      }
    }
    else if (zero == 1) { dp[0] = dp1; dp[1] = dp0+dp1; }
//    else if (zero < maxN) { dp[0] = dp[1] = 1ll*dp1*two[zero-1]%mod+1ll*dp0*two[zero-2]%mod; }
    else { dp[0] = dp[1] = 1ll*dp1*ksm(zero-1)%mod+1ll*dp0*ksm(zero-2)%mod; }

    if (r.y == 0) { dp[1] += dp[0]; dp[0] = 0; }

    if (dp[0] || !r.y) {
      mx = std::max(mx, std::max(l.y, r.y) + (abs(l.x-r.x) - abs(l.y-r.y))/2);
    }

    dp[0] %= mod; dp[1] %= mod;
    std::cout << mx << " " << mx; NL;
  }
  std::cout << (dp[0]+dp[1])%mod << " " << mx;

  return 0;
}


