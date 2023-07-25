#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'
using ll = long long;
ll exgcd(ll a,ll b,ll &x,ll &y) {
    if (!b) {
        x = 1; y = 0;
        return a;
    }
    ll gcd = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return gcd;
}

long long f(long long x, long long y) {
  if (x >= 0 && y >= 0) { return 2*(x+y); }
  else { return (2*labs(x)+2*labs(y)-1); } 
  return 0;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    long long a, b, c; std::cin >> a >> b >> c;
    long long x, y;
    long long g = exgcd(a, b, x, y);
    if (c % g) { std::cout << -1; NL; continue; }
    long long k = a * b / g; //lcm
    long long aa = k/a, bb = k/b; //delta
    
    long long ret = 1e16;
    {
      long long KK = c / g;
      long long X = KK*x, Y = KK*y ;
      if (X < 0) {
        long long z = -X / aa + 1;
        Y -= z * bb;
        X += z * aa;
      }
      long long z = X / aa;
      X -= z*aa; Y += z*bb;

      orep(i, 0, 20) {
        ret = std::min(f(X+aa*i, Y-bb*i), ret);
        ret = std::min(f(X-aa*i, Y+bb*i), ret);
        // std::cout << X+aa*i << " " << Y-bb*i << " " << f(X+aa*i, Y-bb*i, a, b, c); NL;
        // std::cout << X-aa*i << " " << Y+bb*i << " " << f(X-aa*i, Y+bb*i, a, b, c); NL;
      }
    }

    {
      long long KK = c / g;
      long long X = KK*x, Y = KK*y ;
      if (Y < 0) {
        long long z = -Y / bb + 1;
        Y += z * bb;
        X -= z * aa;
      }
      long long z = Y / bb;
      X += z*aa; Y -= z*bb;

      orep(i, 0, 20) {
        ret = std::min(f(X+aa*i, Y-bb*i), ret);
        ret = std::min(f(X-aa*i, Y+bb*i), ret);
        // std::cout << X+aa*i << " " << Y-bb*i << " " << f(X+aa*i, Y-bb*i, a, b, c); NL;
        // std::cout << X-aa*i << " " << Y+bb*i << " " << f(X-aa*i, Y+bb*i, a, b, c); NL;
      }
    }
    std::cout << ret; NL;
  }
  return 0;
}
