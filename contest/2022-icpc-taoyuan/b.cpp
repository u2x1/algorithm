#include <iostream>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int mod = 1e9+7;

long long n, k, r;

struct Mat { int x, y; long long val[3][3]; };

Mat operator*(const Mat &a, const Mat &b) {
  Mat ret { a.x, b.y, {} }; memset(ret.val, 0, sizeof(ret.val));
  orep(i, 0, a.x) {
    orep(j, 0, b.y) {
      orep(z, 0, a.y) {
        ret.val[i][j] = ((a.val[i][z]*b.val[z][j]%mod) + ret.val[i][j]) % mod;
      }
    }
  }
  return ret;
}

long long calR() {
  Mat retm = { 2, 2, { {1, 0}, {0, 1}} },
      a = { 2, 2, { {r-2, 1}, {r-1, 0}} };
  long long kk = k-1;
  while(kk) {
    if (kk&1) { retm = retm*a; }
    kk/=2; a=a*a;
  }
  return (r*(r-1)%mod) * retm.val[0][1] % mod;
}

long long calL() {
  long long ret = 1, a = ((r-2)*(r-2)%mod+(r-1)%mod) % mod;
  long long kk = k*(n-1);
  while(kk) {
    if (kk&1) { ret = ret*a%mod; }
    kk/=2; a=a*a%mod;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::cin >> n >> k >> r;
    std::cout << calR() * calL() % mod; NL;
  }

  return 0;
}
